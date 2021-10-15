#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbAverageForGray;

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            // calculate the average of one pixel value;
            rgbAverageForGray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // set the gray average value in each color value, each pixel;
            image[i][j].rgbtRed = rgbAverageForGray;
            image[i][j].rgbtGreen = rgbAverageForGray;
            image[i][j].rgbtBlue = rgbAverageForGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate each new color value using the Sepia Formula;
            sepiaRed = round(((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)));
            sepiaGreen = round(((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)));
            sepiaBlue = round(((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue)));

            // ensure the result is an integer <= 255;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // set each color value to the sepia value;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // The middle index
    int middle = width / 2.0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < middle; j++)
        {
            // Swap the left side element with right side element
            // temporary pixel = position
            // temp = 0
            RGBTRIPLE temp = image[i][j];
            // position = calculate the swap
            // 0 = 5
            image[i][j] = image[i][width - j - 1];
            // swap position = temp pixel
            // 5 = 0
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float averageRed;
    float averageBlue;
    float averageGreen;

    float average9 = 9.000;
    float average6 = 6.000;
    float average4 = 4.000;

    RGBTRIPLE image2[height][width];

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            // if case 4 (A -> left corner, first row, first column [0][0])
            if (i == 0 && j == 0)
            {
                /* box
                RGBTRIPLE image[i][j]     + RGBTRIPLE image[i][j + 1] +
                RGBTRIPLE image[i + 1][j] + RGBTRIPLE image[i + 1][j + 1]
                */

                averageRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed +
                                    image[i + 1][j + 1].rgbtRed) / average4);

                averageGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen +
                                      image[i + 1][j + 1].rgbtGreen) / average4);

                averageBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i + 1][j + 1].rgbtBlue) / average4);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 4 (B -> right corner, first row, last column [0][width - 1])
            if (i == 0 && j == width - 1)
            {
                /* box
                RGBTRIPLE image[i][j - 1] + RGBTRIPLE image[i][j] +
                RGBTRIPLE image[i + 1][j - 1] + RGBTRIPLE image[i + 1][j]
                */

                averageRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                    image[i + 1][j].rgbtRed) / average4);

                averageGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                      image[i + 1][j].rgbtGreen) / average4);

                averageBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                     image[i + 1][j].rgbtBlue) / average4);

                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 4 (C -> left corner, last row, first column [height - 1][0])
            if (i == height - 1 && j == 0)
            {
                /* box
                RGBTRIPLE image[i - 1][j] + RGBTRIPLE image[i - 1][j + 1] +
                RGBTRIPLE image[i][j] + RGBTRIPLE image[i][j + 1]
                */

                averageRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed +
                                    image[i][j + 1].rgbtRed) / average4);

                averageGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen +
                                      image[i][j + 1].rgbtGreen) / average4);

                averageBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue +
                                     image[i][j + 1].rgbtBlue) / average4);

                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 4 (D -> right corner, last row, last column [height - 1][width - 1])
            if (i == height - 1 && j == width - 1)
            {
                /* box
                RGBTRIPLE image[i - 1][j - 1] + RGBTRIPLE image[i - 1][j] +
                RGBTRIPLE image[i][j - 1] + RGBTRIPLE image[i][j]
                */

                averageRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed +
                                    image[i][j].rgbtRed) / average4);

                averageGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                      image[i][j].rgbtGreen) / average4);

                averageBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                     image[i][j].rgbtBlue) / average4);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 6 (A -> first row)
            if (i == 0 && j > 0 && i == 0 && j < width - 1)
            {
                /* box
                RGBTRIPLE image[i][j] +
                RGBTRIPLE image[i][j - 1] +
                *RGBTRIPLE image[i][j + 1] +
                RGBTRIPLE image[i + 1][j - 1] +
                RGBTRIPLE image[i + 1][j + 1] +
                RGBTRIPLE image[i + 1][j]
                */

                averageRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed +
                                    image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / average6);

                averageGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen +
                                      image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / average6);

                averageBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue +
                                     image[i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / average6);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 6 (B -> last row)
            if (i == height - 1 && j > 0 && i == height - 1 && j < width - 1)
            {
                /* box
                RGBTRIPLE image[i][j] +
                RGBTRIPLE image[i][j - 1] +
                RGBTRIPLE image[i][j + 1] +
                RGBTRIPLE image[i - 1][j] +
                RGBTRIPLE image[i - 1][j - 1] +
                RGBTRIPLE image[i - 1][j + 1]
                */

                averageRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed +
                                    image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / average6);

                averageGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen +
                                      image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / average6);

                averageBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue +
                                     image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / average6);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 6 (C -> first column)
            if (i > 0 && i < height - 1 && j == 0)
            {
                /* box
                RGBTRIPLE image[i][j] +
                RGBTRIPLE image[i - 1][j] +
                RGBTRIPLE image[i + 1][j] +
                RGBTRIPLE image[i][j + 1] +
                RGBTRIPLE image[i - 1][j + 1] +
                RGBTRIPLE image[i + 1][j + 1]
                */

                averageRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed +
                                    image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / average6);

                averageGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                      image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / average6);

                averageBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / average6);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }

            // if case 6 (D -> last column)
            if (i > 0 && i < height - 1 && j == width - 1)
            {
                /* box
                RGBTRIPLE image[i][j] +
                RGBTRIPLE image[i - 1][j] +
                RGBTRIPLE image[i + 1][j] +
                RGBTRIPLE image[i][j - 1] +
                RGBTRIPLE image[i - 1][j - 1] +
                RGBTRIPLE image[i + 1][j - 1]
                */

                averageRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed +
                                    image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / average6);

                averageGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                      image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / average6);

                averageBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / average6);

                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }
            // if case 9 (without the first column, first row, last column, last row)
            // if (i < height - 1 && j < width - 1)
            // else
            if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
            {
                averageRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                    image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                    image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / average9);

                averageGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                      image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                      image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / average9);

                averageBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                     image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                     image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / average9);


                // set the average colour to each pixel:
                image2[i][j].rgbtRed = averageRed;
                image2[i][j].rgbtGreen = averageGreen;
                image2[i][j].rgbtBlue = averageBlue;
            }
        }
    }
    // image = image2;
    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            image[i][j] = image2[i][j];
        }
    }
    return;
}
