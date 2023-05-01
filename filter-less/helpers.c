#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           // Calculate the garyscale
           int gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

           //Make grayscale
           image[i][j].rgbtRed = gray;
           image[i][j].rgbtGreen = gray;
           image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int original_Red = image[i][j].rgbtRed;
            int original_Green = image[i][j].rgbtGreen;
            int original_Blue = image[i][j].rgbtBlue;

            //Calculate the sepua values
            int Red_sepia = round(.393 * original_Red + .769 * original_Green + .189 * original_Blue);
            int Green_sepia = round(.349 * original_Red + .686 * original_Green + .168 * original_Blue);
            int Blue_sepia = round(.272 * original_Red + .534 * original_Green + .131 * original_Blue);

            //Change values upper to 255

            if (Red_sepia > 255)
            {
                Red_sepia = 255;
            }
            if (Green_sepia > 255)
            {
                Green_sepia = 255;
            }
            if (Blue_sepia > 255)
            {
                Blue_sepia = 255;
            }

            // Make sepia

            image[i][j].rgbtRed = Red_sepia;
            image[i][j].rgbtGreen = Green_sepia;
            image[i][j].rgbtBlue = Blue_sepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        //iterate over each pixel in the row up to the midpoint
        for (int j = 0; j < width / 2; j++)
        {
            //swap the pixel
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image [i][width - 1 - j];
            image [i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;

            for (int z = -1; z <= 1; z++)
            {
                for (int x = -1; x <= 1; x++)
                {
                    int ii = i + z;
                    int jj = j + x;
                    if (ii >= 0 && ii < height && jj >= 0 && jj < width)
                    {
                        sum_red += image[ii][jj].rgbtRed;
                        sum_green += image[ii][jj].rgbtGreen;
                        sum_blue += image[ii][jj].rgbtBlue;
                        count++;
                    }
                }
            }

            new_image[i][j].rgbtRed = round((float) sum_red / count);
            new_image[i][j].rgbtGreen = round ((float) sum_green / count);
            new_image[i][j].rgbtBlue = round ((float) sum_blue / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }

    return;
}
