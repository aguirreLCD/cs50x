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
            if (n < 26 || n > 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else if (isdigit(argv[1][i]))
            {
                printf("Key must not contain digit characters.\n");
                return 1;
            }
            else if (isalpha(argv[1][i]))
            {
                if (islower(argv[1][i]))
                {
                    argv[1][i] = toupper(argv[1][i]);
                }
            }
            else
            {
                printf("Key must contain only alphabetical characters.\n");
                return 1;
            }
            // printf("%i\n", n);
            // printf("%i\n", argv[1][i]);
        }
        // printf("Success\n");
        // printf("%s\n", argv[1]);
    }
    else
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // printf("\n");

    // Convert that command-line argument from a string to an int;

    // int key = atoi(argv[1]);

    // int key = strlen(argv[1]);

    string key = argv[1];
    // printf("key = %s\n", key);
    // printf("arg v = %s\n", argv[1]);

    //varrendo a key

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = 0, nj = strlen(key); j < nj; j++)
        {
            if (i == j)
            {
                // printf("if i == j do nothing \n");
            }
            else // i != j
            {
                if (key[i] == key[j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
                else // i != j
                {
                    // printf("key i === %c\n", key[i]);
                    // printf("key j === %c\n", key[j]);
                }
            }
        }
        // printf("key i = %i\n", key[i]);
        // printf("key c = %c\n", key[i]);
    }
    // // Prompt user for plaintext;
    string sPlaintext = get_string("plaintext: ");
    // printf("plaintext = %s\n", sPlaintext);

    //varrendo a plaintext

    // // Iterate over each character of the plaintext:
    int strCipher[strlen(sPlaintext)];   // alocate vector space;

    int alphabeticalIndex;              // first step to encipher: convert from PC to HUMAN (ASCII to alphabetical index);

    int cipherAlphabeticalIndex;

    // string keyLower = key;

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
                cipherAlphabeticalIndex = key[alphabeticalIndex];
                // printf("each cipher upper  = %c\n", (char) cipherAlphabeticalIndex);
                strCipher[i] = cipherAlphabeticalIndex;
            }
            // preserve case: check if is lower; then aply the encipher process;
            else if (islower(sPlaintext[i]))
            {
                // printf("each character lower: %c\n", sPlaintext[i]);
                alphabeticalIndex = sPlaintext[i] - 97;
                cipherAlphabeticalIndex = key[alphabeticalIndex];
                // printf("each cipher to lower  = %c\n", (char) tolower(cipherAlphabeticalIndex));
                strCipher[i] = tolower(cipherAlphabeticalIndex);
            }
        }
        // non-alphabetical characters should be outputted unchanged;
        else
        {
            cipherAlphabeticalIndex = sPlaintext[i];
            strCipher[i] =  cipherAlphabeticalIndex;
        }
    }

    // print-out the ciphertext (without converting the int to a string);
    for (int i = 0, n = strlen(sPlaintext); i < n; i++)
    {
        if (i == 0)
        {
            printf("ciphertext: %c", (char) strCipher[i]);
        }
        else
        {
            printf("%c", (char) strCipher[i]);
        }
    }
    // // After outputting ciphertext, print a newline;
    printf("\n");

    // exit by returning 0 from main;
    return 0;
}