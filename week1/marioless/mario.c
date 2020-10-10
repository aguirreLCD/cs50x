#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring a variable
    int height;

// do-while loop, checking if the input is valid or invalid
    do
    {
        // get_int will prompt the user to type in an integer as input
        height = get_int("Height: ");
    }
    // checking if the input value is between 1 and 8 inclusive
    while (height < 1 || height > 8);


    // creating the pyramid whit hashes - bricks
    for (int iLine = 0; iLine < height; iLine++)
    {
        //creating the column with spaces
        for (int jColumn = height - 1; jColumn > iLine; jColumn--)
        {
            printf(" ");
        }
        //creating the column with hashes
        for (int jColumn = 0; jColumn <= iLine; jColumn++)
        {
            printf("#");
        }

        printf("\n");
    }
}

// mario left

// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {
//     int height;

//     do
//     {
//         height = get_int("Height: ");
//     }
//     while (height < 1 || height > 8);

//     for (int iLine = 0; iLine < height; iLine++)
//     {
//         for (int jColumnSpace = 0; jColumnSpace > 0; jColumnSpace--)
//         {
//             printf(" ");
//         }

//         for (int jColumnHash = 0; jColumnHash <= iLine; jColumnHash++)
//         {
//             printf("#");
//         }

//         printf("\n");
//     }
// }
