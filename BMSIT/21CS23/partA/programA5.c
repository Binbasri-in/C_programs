/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A5- develop a c program to check if a number is prime or not

input: a number
method: find a divisibale number from 3 to n-1
output: a prime or not
*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number: ");
    if (scanf("%d", &n) != 1)
    {
    	printf("Invalid Input\n");
    	return 1;
    }
    if (n <= 0 || n == 1)
    {
    	printf("%d is not a prime number\n", n);
    	return 0;
    }

    for(int i = 3; i < n; i++)
    {
        if(n % i == 0)
        {
            printf("%d is not a prime number\n", n);
            return 0;
        }
    }
    printf("%d is a prime number\n", n);

    return 0;
}
