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
       
//print left spaces and hashes
       for(int jColumnSpaceLeft = height -1; jColumnSpaceLeft > iLine; jColumnSpaceLeft--)
        {
            printf(" ");
        }

        for(int jColumnHashLeft = 0; jColumnHashLeft <= iLine; jColumnHashLeft++)
        {
            printf("#");
        }

//print gap
            printf(" ");
            printf(" ");

//print right spaces and hashes
        for(int jColumnSpaceRight = 0; jColumnSpaceRight > 0; jColumnSpaceRight--)
        {
            printf(" ");
        }

        for(int jColumnHashRight = 0; jColumnHashRight <= iLine; jColumnHashRight++)
        {
            printf("#");
        }

        printf("\n");
    }
}
