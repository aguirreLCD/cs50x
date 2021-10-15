#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char toCipher(char sPlaintext, int asciiIndex, string key);
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
    // Copy that command-line argument;
    string key = argv[1];
    // printf("key = %s\n", key);
    // printf("arg v = %s\n", argv[1]);

    // Validate the key - repeated chars

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = 0, nj = strlen(key); j < nj; j++)
        {
            if (i != j)
            {
                if (key[i] == key[j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        // printf("key i = %i\n", key[i]);
        // printf("key c = %c\n", key[i]);
    }
    // // Prompt user for plaintext;
    string sPlaintext = get_string("plaintext: ");
    // printf("plaintext = %s\n", sPlaintext);

    // Validate the plaintext

    // // Iterate over each character of the plaintext:
    int strCipher[strlen(sPlaintext)];   // alocate vector space;

    // int alphabeticalIndex;              // first step to encipher: convert from PC to HUMAN (ASCII to alphabetical index);

    // int cipherAlphabeticalIndex;

    int asciiIndex = 0;
    // string keyLower = key;

    for (int i = 0, n = strlen(sPlaintext); i < n; i++)
    {
        // validate if isalpha;
        if (isalpha(sPlaintext[i]))
        {
            // preserve case: check if is upper; then aply the encipher process;
            // if (isupper(sPlaintext[i]))
            // {
            //     // printf("each character upper: %c\n", sPlaintext[i]);
            //     alphabeticalIndex = sPlaintext[i] - 65;
            //     cipherAlphabeticalIndex = key[alphabeticalIndex];
            //     // printf("each cipher upper  = %c\n", (char) cipherAlphabeticalIndex);
            //     strCipher[i] = cipherAlphabeticalIndex;
            // }
            // // preserve case: check if is lower; then aply the encipher process;
            // else if (islower(sPlaintext[i]))
            // {
            //     // printf("each character lower: %c\n", sPlaintext[i]);
            //     alphabeticalIndex = sPlaintext[i] - 97;
            //     cipherAlphabeticalIndex = key[alphabeticalIndex];
            //     // printf("each cipher to lower  = %c\n", (char) tolower(cipherAlphabeticalIndex));
            //     strCipher[i] = tolower(cipherAlphabeticalIndex);
            // }
            if (isupper(sPlaintext[i]))
            {
                asciiIndex = 65;
            }
            // preserve case: check if is lower; then aply the encipher process;
            else if (islower(sPlaintext[i]))
            {
                asciiIndex = 97;
            }
            strCipher[i] = toCipher(sPlaintext[i], asciiIndex, key);
        }
        else
        {
            // non-alphabetical characters should be outputted unchanged;
            // cipherAlphabeticalIndex = sPlaintext[i];
            strCipher[i] =  sPlaintext[i];
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
//This function does encipher a given character to the given map key, and it is case-sensitive
char toCipher(char sPlaintext, int asciiIndex, string key)
{
    int alphabeticalIndex = sPlaintext - asciiIndex;
    int cipherAlphabeticalIndex = key[alphabeticalIndex];
    int cipheredChar = cipherAlphabeticalIndex;

    if (asciiIndex == 97)
    {
        cipheredChar = tolower(cipheredChar);
    }

    return  cipheredChar;
}
