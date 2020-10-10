#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Printing a command-line argument -> argc/argv

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // to acces individual characters
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

    // Convert that command-line argument from a string to an int
    int key = atoi(argv[1]);
    printf("key = %i\n", key);

    // Prompt user for plaintext
    string sPlaintext;
    sPlaintext = get_string("plaintext: ");
    // printf("plaintext = %s\n", sPlaintext);

    // validate if isalpha

    int strAscii[strlen(sPlaintext)];


    for (int i = 0, n = strlen(sPlaintext); i < n; i++)
    {
        if (isalpha(sPlaintext[i]))
        {
            if (isupper(sPlaintext[i]))
            {
                // printf("each character upper: %c\n", sPlaintext[i]);
                int alphabeticalIndex = sPlaintext[i] - 65;
                int ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
                int ascii = ciAlphabeticalIndex + 65;
                // printf("each ascii upper = %c\n", (char) ascii);
                strAscii[i] =  ascii;
            }
            else if (islower(sPlaintext[i]))
            {
                // printf("each character lower: %c\n", sPlaintext[i]);
                int alphabeticalIndex = sPlaintext[i] - 97;
                int ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
                int ascii = ciAlphabeticalIndex + 97;
                // printf("each ascii lower = %c\n", (char) ascii);
                strAscii[i] =  ascii;
            }
        }
        else
        {
            int ascii = sPlaintext[i];
            // printf("else: %c\n", (char) ascii);
            // printf("out alpha - your text is a Non alphabetical digit. Please digit a plaintext. \n");
            strAscii[i] =  ascii;
        }
    }

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

        printf("\n");

    return 0;
}












        // isupper



        // islower





    // Encipher

    // first: convert ASCII to ALPHABETICAL INDEX:
    // uppercase = - 65
    // lowercase = - 97

    // PC -> ASCII = 65 to 90: A...Z  | 97 to 122: a...z
    // HUMAN -> ALPHABETICAL INDEX = 0 to 25: A...Z | a ...z

    // 0 to 25 or % 26 - por isso precisa passar primeiro pela validaçao de lower / upper,
    // pq p converter para human, so converte a posiçao, nao considera separado maiusculo / minusculo


    // convert from PC to HUMAN
    // int alphabeticalIndex = sPlaintext[0] - 65;
    // printf("alphabetical index = %i\n", alphabeticalIndex);

    // // HUMAN
    // // then: shift alphabetical index using formula
    // int ciAlphabeticalIndex = (alphabeticalIndex + key) % 26;
    // printf("new alphabetical index ciphered from ci formula = %i\n", ciAlphabeticalIndex);

    // // convert from HUMAN to PC
    // int ascii = ciAlphabeticalIndex + 65;
    // printf("ascii = %c\n", (char) ascii);

    // // ascii -> how to convert int to a string;

    // int n = strlen(sPlaintext);
    // printf("length of the string: plaintext: int:  %i\n", n);


    // convert the plaintext to a string:
   // pegar cada char e store em uma string


