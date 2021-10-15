#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Printing a command-line argument -> argc/argv;
int main(int argc, string argv[])
{
    // accept a single command-line argument;
    if (argc == 2)
    {
        // to acces individual characters;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                // printf("each character: %c\n", argv[1][i]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // printf("Success\n");
        // printf("%s\n", argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // printf("\n");

    // Convert that command-line argument from a string to an int;
    int key = atoi(argv[1]);
    // printf("key = %i\n", key);

    // Prompt user for plaintext;
    string sPlaintext;
    sPlaintext = get_string("plaintext: ");
    // printf("plaintext = %s\n", sPlaintext);

    // Iterate over each character of the plaintext:
    int strAscii[strlen(sPlaintext)];   // alocate vector space;
    int alphabeticalIndex;              // first step to encipher: convert from PC to HUMAN (ASCII to alphabetical index);
    int ciAlphabeticalIndex;            // second step to encipher: HUMAN alphabetical index - 0 to 25 - using formula;
    int ascii;                          // third step to encipher: convert from HUMAN to PC (back to ASCII);

    for (int i = 0, n = strlen(sPlaintext); i < n; i++)
    {
        // validate if isalpha;
        if (isalpha(sPlaintext[i]))
        {
            // preserve case: check if is upper; then aply the encipher process;
            if (isupper(sPlaintext[i]))
            {
                // printf("each character upper: %c\n", sPlaintext[i]);
                alphabeticalIndex = sPlaintext[i] - 65;
                ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
                ascii = ciAlphabeticalIndex + 65;
                // printf("each ascii upper = %c\n", (char) ascii);
                strAscii[i] =  ascii;
            }
            // preserve case: check if is lower; then aply the encipher process;
            else if (islower(sPlaintext[i]))
            {
                // printf("each character lower: %c\n", sPlaintext[i]);
                alphabeticalIndex = sPlaintext[i] - 97;
                ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
                ascii = ciAlphabeticalIndex + 97;
                // printf("each ascii lower = %c\n", (char) ascii);
                strAscii[i] =  ascii;
            }
        }
        // non-alphabetical characters should be outputted unchanged;
        else
        {
            ascii = sPlaintext[i];
            // printf("else: %c\n", (char) ascii);
            // printf("out alpha - your text is a Non alphabetical digit. Please digit a plaintext. \n");
            strAscii[i] =  ascii;
        }
    }

    // print-out the ciphertext (without converting the int to a string);
    for (int i = 0, n = strlen(sPlaintext); i < n; i++)
    {
        if (i == 0)
        {
            printf("ciphertext: %c", (char) strAscii[i]);
        }
        else
        {
            printf("%c", (char) strAscii[i]);
        }
    }
    // After outputting ciphertext, print a newline;
    printf("\n");

    // exit by returning 0 from main;
    return 0;
}

// Encipher process

// first: convert ASCII to ALPHABETICAL INDEX:
// uppercase = - 65
// lowercase = - 97

// PC -> ASCII = 65 to 90: A...Z  | 97 to 122: a...z
// HUMAN -> ALPHABETICAL INDEX = 0 to 25: A...Z | a ...z

// convert from PC to HUMAN
// int alphabeticalIndex = sPlaintext[0] - 65;
// printf("alphabetical index = %i\n", alphabeticalIndex);

// HUMAN
// then: shift alphabetical index using formula
// int ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
// printf("new alphabetical index ciphered from ci formula = %i\n", ciAlphabeticalIndex);

// convert from HUMAN to PC
// int ascii = ciAlphabeticalIndex + 65;
// printf("ascii = %c\n", (char) ascii);

// int n = strlen(sPlaintext);
// printf("length of the string: plaintext: int:  %i\n", n);

// **ascii -> how to convert int to a string;
// how to convert the plaintext to a string;
// improve the name of the variables;


