#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float average(float dividendo, float divisor);

// float averageL(float numberOfLetters, float numberOfWords);

// float averageS(float numberOfSentences, float numberOfWords);

int main(void)
{
    // 1.Prompt for user's text
    string sTextFromUser;
    sTextFromUser = get_string("Text: ");
    // printf("Your text is: %s\n", sTextFromUser);

    // 2.Determines the Length of a string
    // int numberOfCharacters = strlen(sTextFromUser);
    int iCharacters = 0; // index to counter of chars
    int numberOfLetters = 0;
    int numberOfSpaces = 0;
    int numberOfSentences = 0;
    int numberOfDigits = 0;
    int numberOfWords = numberOfSpaces + 1;

    // 3.Count the number of letters / words / sentences
    // 3.1 Count number of characters up until '\0' (aka NUL - end of a string)
    while (sTextFromUser[iCharacters] != '\0')
    {

        if (sTextFromUser[iCharacters] >= 'a' && sTextFromUser[iCharacters] <= 'z')  // >= 65 <= 90 || >= 97 <= 122
        {
            numberOfLetters++;
        }
        else if (sTextFromUser[iCharacters] >= 'A' && sTextFromUser[iCharacters] <= 'Z')
        {
            numberOfLetters++;
        }
        else if (sTextFromUser[iCharacters] == ' ')
        {
            numberOfSpaces++;
            numberOfWords++;
        }
        else if (sTextFromUser[iCharacters] == '!' || sTextFromUser[iCharacters] == '?' || sTextFromUser[iCharacters] == '.')
        {
            numberOfSentences++;
        }
        else if (sTextFromUser[iCharacters] >= '0' && sTextFromUser[iCharacters] <= '9')
        {
            numberOfDigits++;
        }

        iCharacters++;
    }
    printf("Your text has: %i characters\n", numberOfLetters);
    printf("Your text has: %i words\n", numberOfWords);
    printf("Your text has: %i sentences\n", numberOfSentences);
    printf("Your text has: %i digits\n", numberOfDigits);

    // float averageL;
    // averageL = ((float) numberOfLetters / (float) numberOfWords) * 100;
    // printf("average L: %i letters per 100 words.\n", (int) round(averageL(numberOfLetters, numberOfWords)));

    // float averageS;
    // averageS = ((float) numberOfSentences / (float) numberOfWords) * 100;
    // printf("average S: %i sentences per 100 words.\n", (int) round(averageS(numberOfSentences, numberOfWords)));

    // Coleman-Liau index
    float index = 0.0588 * average(numberOfLetters, numberOfWords) - 0.296 * average(numberOfSentences, numberOfWords) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", (int) round(index));
    }
    printf("\n");
}

// float averageL(float numberOfLetters, float numberOfWords)
// {
//     float averageL = (numberOfLetters / numberOfWords) * 100;
//     return (int) averageL;
// }

// float averageS(float numberOfSentences, float numberOfWords)
// {
//     float averageS = (numberOfSentences / numberOfWords) * 100;
//     return (int) averageS;
// }

// this function calculates the percentual average of 2 values;
float average(float dividendo, float divisor)
{
    float averageResult = (dividendo / divisor) * 100;
    return (int) averageResult;
}
