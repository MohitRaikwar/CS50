#include "helpers.h"
#include<math.h>
#include<stdlib.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j<width;j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen=image[i][j].rgbtGreen;
            int originalBlue=image[i][j].rgbtBlue;
            int average=round((originalRed+originalGreen+originalBlue)/3.0);
            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;
        }

    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j<width;j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen=image[i][j].rgbtGreen;
            int originalBlue=image[i][j].rgbtBlue;
            int sepiaRed=round(.393*originalRed+.769*originalGreen+.189*originalBlue);
            int sepiaGreen=round(.349*originalRed+.686*originalGreen+.168*originalBlue);
            int sepiaBlue=round(.272*originalRed+.534*originalGreen+.131*originalBlue);
            if(sepiaRed>255)
             sepiaRed/=255;
            if(sepiaBlue>255)
             sepiaBlue/=255;
            if(sepiaGreen>255)
             sepiaGreen/=255;
            image[i][j].rgbtRed=sepiaRed;
            image[i][j].rgbtGreen=sepiaGreen;
            image[i][j].rgbtBlue=sepiaBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for(int i=0;i<height;i++)
    {
        int n=width;                //Helps in swapping ith row pixel with first onee
        for(int j=0;j<width/2;j++)
        {
           tmp[i][j]=image[i][j];
           image[i][j]=image[i][--n]; //image[i][j]=image[i][n-1];
           image[i][n]=tmp[i][j];     //image[n-1][j]=tmp[i][j];
                                      //n--;
        }
    }
    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
