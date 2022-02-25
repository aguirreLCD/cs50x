# Implement a program that calculates the minimum number of coins required to give a user change;
# first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made;
# If the user fails to provide a non-negative value,
# your program should re-prompt the user for a valid amount again and again until the user complies.
# Incidentally, so that we can automate some tests of your code,
# we ask that your program’s last line of output be only the minimum number of coins possible: an integer followed by a newline.

from cs50 import get_float

change = get_float("How much change is owed (in dollars)? ")
while change <= 0:
    change = get_float("How much change is owed (in dollars)? ")

# converting dollars to cents
cents = round(change * 100)
print(f"Change in cents: ", cents)

# computing coins: tracking how many coins used and remaining change owed
counter = 0
quarter = 0
dime = 0
nickel = 0
penny = 0
totalCoins = 0

while (cents > 0):
    while (cents >= 25):
        counter += 1
        quarter += 1
        cents = cents - 25

    while (cents >= 10):
        counter += 1
        dime += 1
        cents = cents - 10

    while (cents >= 5):
        counter += 1
        nickel += 1
        cents = cents - 5

    while (cents >= 1):
        counter += 1
        penny += 1
        cents = cents - 1

totalCoins = quarter + dime + nickel + penny

# output the answer, the result
print(f"Quarters: ", quarter)
print(f"Dimes: ", dime)
print(f"Nickels: ", nickel)
print(f"Pennies: ", penny)
print(f"Change in coins: ", totalCoins)