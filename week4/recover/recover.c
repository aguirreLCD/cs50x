#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // Accept exactly one command-line argument;
    if (argc != 2)
    {
        printf("Usage: ./recover forensic image name\n");
        return 1;
    }

    // Open memory card;
    char *card_raw = argv[1];
    FILE *card_pointer = fopen(card_raw, "r");

    if (card_raw == NULL)
    {
        printf("Unable to open: %s\n", card_raw);
        return 1;
    }

    // Loop
    // Create a buffer to hold the data until it is written or read;
    unsigned char buffer[512];

    // Create a counter to jpg -> to keep track of the number of the images;
    int counter_jpg = 0;

    // Create a counter to file;
    int counter_file = 0;

    // Create a file to save the images;
    char filename[8]; // 000.jpg -> 8 = 3 digits + 1 dot + 3 char + 1 for the /0 (null terminating char);

    // Create a file pointer to output data from input file;
    FILE *output_file = NULL;

    // fread function takes 4 parameters:
    // data = pointer to a buffer;
    // size = size of each element to read; number of bytes of each element to read;
    // number = numbers of elements to read;
    // inptr = input, the file that you are going to actually read data from ;

    // fread(data, size, number, inptr) -> to read the files;
    while (fread(buffer, 512, 1, card_pointer) == 1)
    {
        // Look for beginning of a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter_jpg == 1) // jpg byte already opened, then close;
            {
                fclose(output_file);
            }
            else // if not the new one, it means you found a new one...then increment;
            {
                counter_jpg = 1;
            }

            sprintf(filename, "%03i.jpg", counter_file); // to print filename = 000.jpg;
            output_file = fopen(filename, "w"); // open file to input // write;
            counter_file++;
        }

        if (counter_jpg == 1) // jpg from buffer to filename;
        {
            fwrite(&buffer, 512, 1, output_file);
        }
    }
    fclose(card_pointer);
    fclose(output_file);

    return 0;
}
