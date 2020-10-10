#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);


   for(int iLine = 0; iLine < height; iLine++)
   {
       for(int jColumnSpace = 0; jColumnSpace > 0; jColumnSpace--)
        {
            printf(" ");
        }

        for(int jColumnHash = 0; jColumnHash <= iLine; jColumnHash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
