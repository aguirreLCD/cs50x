#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //initializing variables: declaring and assigning
    float change;
    int cents;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;
    int counter = 0;

    //checking if the input is negative, re-prompt until greater than 0
    do
    {
        //get the user's input
        change = get_float("How much change is owed (in dollars)?\n");
    }
    while (change <= 0);

    //converting dollars to cents
    cents = round(change * 100);
    printf("Change in cents: %i\n", cents);

    //computing coins: tracking how many coins used and remaining change owed
    do
    {
        while (cents >= 25)
        {
            counter++;
            quarter++;
            cents = cents - 25;
        }

        while (cents >= 10)
        {
            counter++;
            dime++;
            cents = cents - 10;
        }

        while (cents >= 5)
        {
            counter++;
            nickel++;
            cents = cents - 5;
        }

        while (cents >= 1)
        {
            counter++;
            penny++;
            cents = cents - 1;
        }
    }
    while (cents > 0);

    int totalCoins = quarter + dime + nickel + penny;

    //output the answer, the result
    printf("Quarters: %i\n", quarter);
    printf("Dimes: %i\n", dime);
    printf("Nickels: %i\n", nickel);
    printf("Pennies: %i\n", penny);
    printf("Change in coins: %i\n", totalCoins);
}