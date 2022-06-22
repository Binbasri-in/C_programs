#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop throw each pixel and get its gray avrage and change every color
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = (int) round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop throw each pixel and get its sepia number and change every color
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = (int) round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = (int) round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int) round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop throw each pixel and swap with the opposite one in the same row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtRed = tempRed;
            image[i][width - 1 - j].rgbtGreen = tempGreen;
            image[i][width - 1 - j].rgbtBlue = tempBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //loop throw each pixel and do the work
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int count = 0;
            for (int k = 0; k < 3; k++)
            {
                int ith = i + k - 1;
                if (ith == -1 || ith == height)
                {
                    continue;
                }
                for (int n = 0; n < 3; n++)
                {
                    int jth = j + n - 1;
                    if (jth == -1 || jth == width)
                    {
                        continue;
                    }
                    count += 1;
                    totalRed += image[ith][jth].rgbtRed;
                    totalGreen += image[ith][jth].rgbtGreen;
                    totalBlue += image[ith][jth].rgbtBlue;

                }
            }
            image[i][j].rgbtRed = (int) round(totalRed / (float)count);
            image[i][j].rgbtGreen = (int) round(totalGreen / (float)count);
            image[i][j].rgbtBlue = (int) round(totalBlue / (float)count);
        }
    }
}
