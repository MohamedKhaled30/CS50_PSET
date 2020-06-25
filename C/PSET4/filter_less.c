#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg ;
    int sum = 0;
    for (int i = 0 ; i < height ; i++)//iterate for each row
    {
        for (int j = 0 ; j < width ; j++)//iterate for each col
        {
            sum += image[j][i].rgbtBlue ;
            sum += image[j][i].rgbtGreen;
            sum += image[j][i].rgbtRed;
            avg = round(sum / 3.00);
            sum = 0;
            image[j][i].rgbtBlue = avg;
            image[j][i].rgbtGreen = avg;
            image[j][i].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0 ; i < height ; i++)//iterate for each row
    {
        for (int j = 0 ; j < width ; j++)//iterate for each col
        {
            float red = image[j][i].rgbtRed ;
            float green = image[j][i].rgbtGreen;
            float blue = image[j][i].rgbtBlue;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            if (sepiaRed <= 255)
            {
                image[j][i].rgbtRed = sepiaRed;
            }
            else
            {
                image[j][i].rgbtRed = 255;
            }
            if (sepiaGreen <= 255)
            {
                image[j][i].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[j][i].rgbtGreen = 255;
            }
            if (sepiaBlue <= 255)
            {
                image[j][i].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[j][i].rgbtBlue = 255;
            }

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp0;
    int temp1;
    int temp2;

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width / 2 ; j++)
        {
            //put rgb from first pixle into temp
            temp0 = image[i][j].rgbtBlue;
            temp1 = image[i][j].rgbtRed;
            temp2 = image[i][j].rgbtGreen;

            //put rgb form versa into his versus
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

            //put rgb from temp to the first
            image[i][width - j - 1].rgbtBlue = temp0;
            image[i][width - j - 1].rgbtRed = temp1;
            image[i][width - j - 1].rgbtGreen = temp2;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sum_blue;
    int sum_green;
    int sum_red;
    float counter;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sum_blue = 0;
            sum_green = 0;
            sum_red = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sum_blue += image[j + k][i + h].rgbtBlue;
                    sum_green += image[j + k][i + h].rgbtGreen;
                    sum_red += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sum_blue / counter);
            temp[j][i].rgbtGreen = round(sum_green / counter);
            temp[j][i].rgbtRed = round(sum_red / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
