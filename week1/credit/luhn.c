#include <stdio.h>

// #define DEBUG

// Function prototypes
long get_cc();
int validate(long n);

int main()
{
    switch (validate(get_cc()))
    {
        case 3:
            printf("AMEX\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
        case 6:
            printf("DISCOVER\n");
            break;
        default:
            printf("INVALID\n");
    }
}

long get_cc()
{
    printf("Enter a credit card number: ");
    long n;
    scanf("%ld", &n);
    return n;
}

int validate(long n)
{
    long number = n;

    #ifdef DEBUG
    printf("Number: %ld\n", number);
    #endif

    int sum = 0;
    sum = number % 10;                 // add checksum
    number = number / 10;              // chop checksum off
    
    while(number)
    {
        int temp = (number % 10) * 2;  // get rightmost digit and double
        if (temp > 9)                  // if 2 digit number add digits together
        {
            temp = temp - 9;
        }
        sum = sum + temp;              // add digit to sum
        number = number / 10;          // chop rightmost digit off
        temp = number % 10;            // get rightmost digit
        sum = sum + temp;              // add interleaved digit to sum
        number = number / 10;          // chop right digit off
    }
    while (n > 10)                     // get leftmost digit
    {
        n = n / 10;
    }

    #ifdef DEBUG
    printf("Sum: %d\nLeftmost: %ld\n", sum, n);
    #endif

    if (sum % 10)                      // invalid card number
    {
        return -1;
    }
    return n;                          // return leftmost digit
}