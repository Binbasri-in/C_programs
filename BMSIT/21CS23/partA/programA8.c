/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A8- develop a c program to find the square root of the a given number

input: a positive number
method: take number by number and revers
output: the reversed number and is it a palindom or not
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1)
    {
    	printf("Invalid input\n");
    	return 0;
    }
    
    double x = 0.00001;
    while (x * x < n)
    {
        x += 0.00001;
    }
    printf("Square root of %d is %.2lf\n", n, x);

    return 0;
}
