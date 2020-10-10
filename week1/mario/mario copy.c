#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declaring a variable
    int height;

    //do-while loop to execute at least once, then check if the input value is between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //creating a row
    for (int iLine = 0; iLine < height; iLine++)
    {
        //print the left spaces
        for (int jColumnSpaceLeft = height - 1; jColumnSpaceLeft > iLine; jColumnSpaceLeft--)
        {
            printf(" ");
        }

        //print the left hashes
        for (int jColumnHashLeft = 0; jColumnHashLeft <= iLine; jColumnHashLeft++)
        {
            printf("#");
        }

        //print the gap between the 2 pyramids
        printf(" ");
        printf(" ");

        //print the right spaces
        for (int jColumnSpaceRight = 0; jColumnSpaceRight > 0; jColumnSpaceRight--)
        {
            printf(" ");
        }

        //print the right hashes
        for (int jColumnHashRight = 0; jColumnHashRight <= iLine; jColumnHashRight++)
        {
            printf("#");
        }

        //print the new line
        printf("\n");
    }
}
