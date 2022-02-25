import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database

        user_name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        birthdays = db.execute("INSERT INTO birthdays (name, month, day) VALUES (:user_name, :month, :day)", user_name=user_name, month=month, day=day);

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html

        birthdays = db.execute("SELECT * FROM birthdays ORDER BY month ASC");

        return render_template("index.html", birthdays=birthdays)


@app.route("/remove", methods=["POST"])
def remove():

        # birthdays = db.execute("SELECT * FROM birthdays ORDER BY month ASC");

        # remove_name =  request.form.get("remove_name")
        # remove_month =  request.form.get("remove_month")
        # remove_day =  request.form.get("remove_day")

        # birthdays = db.execute("DELETE FROM birthdays WHERE name=:remove_name AND month=:remove_month AND day=:remove_day", remove_name=remove_name, remove_month=remove_month, remove_day=remove_day);

        birthdays = db.execute("DELETE FROM birthdays WHERE name=:remove", remove=request.form['birthday_name'] );

        return redirect("/")
