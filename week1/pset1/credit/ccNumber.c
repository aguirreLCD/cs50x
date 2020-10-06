#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    long cardNumber;
    int lastDigit;
    int minusLastDigit;
    long cardNumberNew;
    long secondToLastDigit;
    long thirdToLastDigit;


        //ask credit card number - prompt the input
        cardNumber = get_long("Please digit your credit card number:\n");
        printf("credit card number: %li\n", cardNumber);



    do
    {

            lastDigit = cardNumber % 10;
            printf("last digit: %i\n", lastDigit); //print the last digit

            secondToLastDigit = ((cardNumber / 10) % 10);
            printf("second to last digit: %li\n", secondToLastDigit); //print the last digit

            thirdToLastDigit = ((cardNumber / 100) % 10);
            printf("third to last digit: %li\n", thirdToLastDigit); //print the last digit


            // minusLastDigit = cardNumber / 10;
            // printf("minus last digit: %i\n", minusLastDigit);

            // cardNumberNew = minusLastDigit;
            // printf("new card number: %li\n", cardNumberNew);



    }
    while (cardNumber < 0);



        //function that converts the cardNumber to an split of digits
            // how to adapt this to get the second to last digit, then the 4th to last digit and so on...
            // lastDigit = cardNumber % 10;  //split last digit from cardNumber
            // printf("last digit: %i\n", lastDigit); //print the last digit

            // minusLastNumber = cardNumber / 10;
            // printf("minusLastNumber: %i\n", minusLastNumber); //print the card number without the last digit


        //CHECKSUM calculate if credit car number is valido or not, based on the checksum have a final digit 0
            //Multiply every other digit by 2, starting with the number’s second-to-last digit
            //Add those products’ digits together
            //Add the sum to the sum of the digits that weren’t multiplied by 2
            //Check if the total’s last digit is 0; if 0 the number is valid



        //CHECK-FLAG
            //check for card length and starting digits
                //here i need find the pattern for the flags of AMEX, MASTERCARD, VISA, or INVALID
                    // American Express: 15 digits, starts with 34 or 37;
                    // MasterCard: 16 digits, starts with 51, 52, 53, 54 or 55;
                    // Visa: 13 or 16 digits, starts with 4;


        //MATCH CHECKSUM AND CHECK-FLAG
            //if matches the checksum and also the check-flag, print out AMEX, MASTERCARD, VISA, or INVALID
                // if()
                // {
                //     printf("AMEX\n");
                // }
                // else if ()
                // {
                //     printf("MASTERCARD\n");

                // }
                // else if ()
                // {
                //     printf("VISA\n");

                // }
                // else ()
                // {
                //     printf("INVALID\n");

                // }

}
