/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B15- Design, develop and execute a C program with / without using functions to 
Implement Matrix multiplication and validate the rules of multiplication

input: The two matrices to be multiplied
method: matrix multiplication
output: The product of the two matrices
*/
#include <stdio.h>

int matrixMultiplication(int a[][3], int b[][3], int c[][3]);

int main(void)
{
    int a[3][3], b[3][3], c[3][3];
    printf("Enter the elements of the first matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    matrixMultiplication(a, b, c);
    printf("The product of the two matrices is: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int matrixMultiplication(int a[][3], int b[][3], int c[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
