/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A8- develop a c program to find the square root of the a given number

input: the number to be sqaure rooted
method: start from 0.00001 and find the square root till the given number is found
output: the square root of the number
*/
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
    	printf("Invalid input\n");
    	return 0;
    }
    
    double x = 0.00001;
    while (x * x < n)
    {
        x += 0.00001;
    }
    printf("Square root of %d is %.3lf\n", n, x);

    return 0;
}