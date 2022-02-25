import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # return apology("TODO")

    # Query db for the current user
    current_user = db.execute("SELECT username FROM users WHERE id = :current_user_id", current_user_id=int(session["user_id"]))[0]["username"]

    # Query db for the amount of cash of the current user
    cash = db.execute("SELECT cash FROM users WHERE id = :current_user_id", current_user_id=int(session["user_id"]))[0]["cash"]

    # Query db for the wallet of the current user
    wallets = db.execute("SELECT * FROM wallet WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

    if not wallets:
        return render_template("index.html", current_user=current_user, cash=usd(cash), wallets=wallets)

    else:
        stocks = db.execute("SELECT stock_symbol FROM wallet WHERE user_id = :current_user_id AND shares != :shares", current_user_id=int(session["user_id"]), shares=0)

        for stock in stocks:
            symbol_quoted= lookup(stock["stock_symbol"])["symbol"]
            # symbol=symbol_quoted["symbol"]
            current_price_quoted = lookup(stock["stock_symbol"])["price"]
            # current_price=usd(current_price_quoted["price"])
            # print(symbol_quoted)
            # print(usd(current_price_quoted))

            db.execute("UPDATE wallet SET current_price = :current_price_quoted WHERE user_id = :current_user_id AND stock_symbol = :stock_symbol", current_user_id=int(session["user_id"]), current_price_quoted=current_price_quoted, stock_symbol=symbol_quoted)

        wallets = db.execute("SELECT stock_symbol, stock_name, shares, stock_price, current_price FROM wallet WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

        # Query db for the current user history
        historys = db.execute("SELECT * FROM history WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

        if not historys:
            return render_template("index.html", current_user=current_user, cash=usd(cash), wallets=wallets)

        money = db.execute("SELECT shares, stock_price FROM history WHERE user_id = :current_user_id GROUP BY shares, stock_price HAVING deal = :deal", current_user_id=int(session["user_id"]), deal="buy")

        amount_buy = 0
        for buy in money:
            shares=buy["shares"]
            stock_price=buy["stock_price"]
            amountbuy=int(shares) * int(buy["stock_price"])
            # print(shares)
            # print(stock_price)
            # print(amountbuy)
            amount_buy += amountbuy

        invests = db.execute("SELECT shares, stock_price FROM history WHERE user_id = :current_user_id GROUP BY shares, stock_price HAVING deal = :deal", current_user_id=int(session["user_id"]), deal="sell")

        amount_sell = 0
        for sell in invests:
            shares=sell["shares"]
            stock_price=sell["stock_price"]
            amountsell=int(shares) * int(sell["stock_price"])
            # print(shares)
            # print(stock_price)
            # print(amountsell)
            amount_sell += amountsell

        # savings = cash - buy + sell

        quid = amount_buy - amount_sell

        cash_init = 10000

        # savings = cash_init - amount_buy + amount_sell

        savings = cash_init - quid

        return render_template("index.html", current_user=current_user, cash=usd(cash), wallets=wallets, stocks=stocks, historys=historys, amount_buy = usd(amount_buy), amount_sell = usd(amount_sell), quid=usd(quid), savings=usd(savings))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # return apology("TODO")

    if request.method == "POST":

        # stock that user wants to buy -> lookup func goes to API and returns a dict
        stock_tobuy = lookup(request.form.get("symbol"))

        # number of shares that user wants to buy
        shares = request.form.get("shares")

        if stock_tobuy == None:
            return apology("invalid stock", 402)

        elif not shares.isdigit() or int(shares) < 1:
            return apology("invalid amount of stock to buy", 400)

        # Query db for the amount of cash of the current user
        cash = db.execute("SELECT cash FROM users WHERE id = :current_user_id", current_user_id=int(session["user_id"]))

        # purchase = price of the stock * number of shares to buy
        purchase = stock_tobuy["price"] * int(shares)

        # Make sure user have enough cash
        if int (cash[0]["cash"]) < purchase:
            return apology("Not enough money available", 403)

        else:
            # Query db to subtract the purchase
            cash_update_buy = db.execute("UPDATE users SET cash = cash - :purchase WHERE id = :current_user_id", purchase=purchase, current_user_id=int(session["user_id"]))

            # TODO: save transaction in history and portfolio(wallet)

            # Query db to insert into history
            historys = db.execute("INSERT INTO history (user_id, stock_symbol, shares, stock_price, deal) VALUES (:user_id, :stock_symbol, :shares, :stock_price, :deal)",
                        user_id=int(session["user_id"]), stock_symbol=stock_tobuy["symbol"], shares=int(request.form.get("shares")), stock_price=stock_tobuy["price"], deal="buy")

            stocks_in_wallet = db.execute("SELECT stock_symbol, shares FROM wallet WHERE stock_symbol = :stock_tobuy", stock_tobuy=request.form.get("symbol"))

            if not stocks_in_wallet:
                wallets=db.execute("INSERT INTO wallet (user_id, stock_symbol, stock_name, shares, stock_price, deal) VALUES (:current_user_id, :stock_symbol, :stock_name, :shares, :stock_price, :deal)",
                        current_user_id=int(session["user_id"]), stock_symbol=stock_tobuy["symbol"], stock_name=stock_tobuy["name"], shares=int(request.form.get("shares")), stock_price=stock_tobuy["price"], deal="buy")
            else:
                wallets=db.execute("UPDATE wallet SET shares = shares + :shares_tobuy WHERE stock_name = :stock_name", shares_tobuy=int(request.form.get("shares")), stock_name=stock_tobuy["name"] )

            return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:

        wallets = db.execute("SELECT * FROM wallet WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

        return render_template("buy.html", wallets=wallets)

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # return apology("TODO")

    # Query db for the current user
    current_user = db.execute("SELECT username FROM users WHERE id = :current_user_id", current_user_id=int(session["user_id"]))[0]["username"]

    # Query db for the current user history
    historys = db.execute("SELECT * FROM history WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

    if not historys:
        return render_template("history.html", current_user=current_user, historys=historys)

    else:
        money = db.execute("SELECT shares, stock_price FROM history WHERE user_id = :current_user_id GROUP BY shares, stock_price HAVING deal = :deal", current_user_id=int(session["user_id"]), deal="buy")

        amount_buy = 0
        for buy in money:
            shares=buy["shares"]
            stock_price=buy["stock_price"]
            amountbuy=int(shares) * int(buy["stock_price"])
            # print(shares)
            # print(stock_price)
            # print(amountbuy)
            amount_buy += amountbuy

        invests = db.execute("SELECT shares, stock_price FROM history WHERE user_id = :current_user_id GROUP BY shares, stock_price HAVING deal = :deal", current_user_id=int(session["user_id"]), deal="sell")

        amount_sell = 0
        for sell in invests:
            shares=sell["shares"]
            stock_price=sell["stock_price"]
            amountsell=int(shares) * int(sell["stock_price"])
            # print(shares)
            # print(stock_price)
            # print(amountsell)
            amount_sell += amountsell

        # savings = cash - buy + sell

        quid = amount_buy - amount_sell

        cash_init = 10000

        savings = cash_init - quid

        return render_template("history.html", current_user=current_user, historys=historys, amount_buy = usd(amount_buy), amount_sell = usd(amount_sell), quid=usd(quid), savings=usd(savings))

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # return apology("TODO")

    if request.method == "POST":

        stock_quoted = lookup(request.form.get("symbol"))

        if stock_quoted == None:
            return apology("invalid stock", 403)

        else:
            return render_template("quoted.html", name=stock_quoted["name"], symbol=stock_quoted["symbol"], price=usd(stock_quoted["price"]))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("must provide password", 403)

        # Insert in the database
        registered = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)", username=request.form.get("username"), hash=generate_password_hash(request.form.get("password")))

        # Ensure username is not repeated
        if not registered:
            return apology("username unavailable", 403)

         # Start session
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # Remember which user las logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # return apology("TODO")

    if request.method == "POST":

        # stock that user wants to sell -> lookup func returns a dict
        stock_tosell = lookup(request.form.get("symbol"))

        shares_tosell = request.form.get("shares")

        shares_in_wallet = db.execute("SELECT shares FROM wallet WHERE stock_symbol = :stock_tosell", stock_tosell=request.form.get("symbol"))

        if not shares_in_wallet:
            return apology("stock unavailable...", 402)

        if int(shares_tosell) > shares_in_wallet[0]["shares"]:
            return apology("Not enough shares available...", 402)

        if stock_tosell == None:
            return apology("invalid stock", 402)

        sale = stock_tosell["price"] * int(shares_tosell)

        cash_update_sell = db.execute("UPDATE users SET cash = cash + :sale WHERE id = :current_user_id", sale=sale, current_user_id=int(session["user_id"]))

        # Query db to insert into history
        historys = db.execute("INSERT INTO history (user_id, stock_symbol, shares, stock_price, deal) VALUES (:user_id, :stock_symbol, :shares, :stock_price, :deal)",
                        user_id=int(session["user_id"]), stock_symbol=stock_tosell["symbol"], shares=request.form.get("shares"), stock_price=stock_tosell["price"], deal="sell")

        # Query db to insert into wallet
        wallets = db.execute("UPDATE wallet SET shares = shares - :shares_tosell WHERE stock_name = :stock_name", shares_tosell=int(request.form.get("shares")), stock_name=stock_tosell["name"])

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        wallets = db.execute("SELECT * FROM wallet WHERE user_id = :current_user_id", current_user_id=int(session["user_id"]))

        return render_template("sell.html", wallets=wallets)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
