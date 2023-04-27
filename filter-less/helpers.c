#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiared;
    int sepiagreen;
    int sepiablue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            sepiared = (round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            sepiagreen = (round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiablue = (round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            if (sepiared > 255)
            {
                sepiared = 255;
            }

            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }

            if (sepiablue > 255)
            {
                sepiablue = 255;
            }

            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;

        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j =  0; j < (width/2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    float blurred;
    float blurgreen;
    float blurblue;

    //j width  i height

    for (int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            //if upper left corner
            if(j == 0 && i == 0 )
            {
                blurred = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.000);
                blurblue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j +1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;
            }
            //if upper right corner
            else if (i == 0 && j == (width - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.000);
                blurgreen =  round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.000);
                blurblue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;
            }

            //if lower right corner

            else if ( i == (height - 1) && j == (width - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.000);
                blurblue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;

            }
            //if lower left corner

            else if ( i == (height - 1) && j == 0)
            {
                blurred = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.000);
                blurblue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;
            }

            //if left edge
            else if (j == 0 && i != 0 && i != (height - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.000);
                blurblue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;

            }

            //if right edge

            else if ( i != 0 && i != (height - 1) && j == (width - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6.000);
                blurblue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;

            }
            //if top edge

            else if ( i == 0 && j != 0 && j != (width - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image [i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.000);
                blurblue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image [i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;
            }
            //if bottom edge

            else if ( i == (height - 1) && j != 0 && j != (width - 1))
            {
                blurred = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.000);
                blurblue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;

            }
            //else if not edges/corners

            else
            {
                blurred = round((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.000);
                blurgreen = round((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.000);
                blurblue = round((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.000);

                copy[i][j].rgbtRed = blurred;
                copy[i][j].rgbtGreen = blurgreen;
                copy[i][j].rgbtBlue = blurblue;

            }
        }
    }

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }

    return;
}
