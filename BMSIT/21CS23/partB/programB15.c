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

int matrixMultiplication(int a[][10], int b[][10], int c[][10]);

void read_2d(int a[][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int main(void)
{
    int a[10][10], b[10][10], c[10][10], m, n, p, q;
    printf("Enter number of rows of Matrix A: ");
    scanf("%d", &m);
    printf("Enter number of columns of Matrix A: ");
    scanf("%d", &n);
    printf("Enter number of rows of Matrix B: ");
    scanf("%d", &p);
    printf("Enter number of columns of Matrix A: ");
    scanf("%d", &q);
    if (n != p)
    {
        printf("Multiplication is not possible\n");
        return 1;
    }

    printf("Enter the elements of the first matrix\n");
    
    read_2d(a, m, n);

    printf("Enter the elements of the second matrix\n");
    read_2d(b, p, q);

    matrixMultiplication(a, b, c, m, n, p, q);
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

int matrixMultiplication(int a[][10], int b[][10], int c[][10], int m, int n, int p, int q)
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
