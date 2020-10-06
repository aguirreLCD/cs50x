#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //this variable will save the full number, and will be untouched, not to be modified ;
    long creditCardNumber;

    do
    {
        creditCardNumber = get_long("Please enter the credit car number:\n");
        // printf("credit card number: %li\n", creditCardNumber);
    }
    while (creditCardNumber <= 0);

    //reassign a variable to be modified during the checksum;
    long creditCardNumberNew = creditCardNumber;

    //initializing a variable to store the sum;
    int sum = 0;

    //initializing a variable to store the count of digits;
    int counter = 0;

    //initializing a variable to store the divisor;
    long divisor = 10;

    //1st step: get last digit -> sum -> skip one - third to last digit -> sum -> skip one...and so on;
    //1. Iterating through the card number;
    while (creditCardNumberNew > 0)
    {
        //2.Using modulo to get the last digit;
        int lastDigit = creditCardNumberNew % 10;

        //3. Adding last digit to sum;
        sum = sum + lastDigit;

        //4. Dividing the CC number by 100 (to move 2 digits over);
        creditCardNumberNew = creditCardNumberNew / 100;
    }

    //2nd step: get second to last digit -> multiply by 2 -> add sum -> skip one - 4th to last digit -> multiply by 2 -> add sum -> skip one...and so on;
    //1. Dividing the credit card number by 10 (to start to the second to last number);
    creditCardNumberNew = creditCardNumber / 10;

    //2. Iterating through the credit card number;
    while (creditCardNumberNew > 0)
    {
        //3. Using modulo to get the last digit;
        int lastDigit = creditCardNumberNew % 10;

        //4. Multiply the last digit by 2 and add to the sum;
        int timesTwo = lastDigit * 2;

        //4.1 Using modulo for the last digit; 4.2 Using division for the 1st digit;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);

        //5. Dividing the credit card number by 100 (to move 2 digits over);
        creditCardNumberNew = creditCardNumberNew / 100;
    }

    //checking the conditionals for the flags;

    //return the initial value
    creditCardNumberNew = creditCardNumber;

    //count the length of the credit card number
    while (creditCardNumberNew != 0)
    {
        creditCardNumberNew = creditCardNumberNew / 10;
        counter++;
    }

    // printf("length: %i\n", counter);

    // loop to get the first 2 digits
    for (int i = 0; i < counter - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = creditCardNumber / divisor;
    int firstTwoDigits = creditCardNumber / (divisor / 10);

    //printf("first digit: %i\n", firstDigit);
    //printf("first 2 digits: %i\n", firstTwoDigits);

    //Final checksum;
    if (sum % 10 == 0)
    {
        if (counter == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (counter == 16 &&
                 (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((counter == 13 || counter == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}