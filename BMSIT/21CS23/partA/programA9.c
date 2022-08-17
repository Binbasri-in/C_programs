/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A9- develop a c program to evaluate a polynomial of n degree

input: a positive number
method: store the coefficients and sum together
output: the sum of all parts
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, x, sum;
	
	printf("Enter a positive number as the degree: ");
	scanf("%d", &n);
	int a[n+1];
	printf("Enter the coefficients in ascending order\n");
	for (int i = 0 ; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the value of x: ");
	scanf("%d", &x);
	
	sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += a[i] * pow(x, i);
	}
	printf("The sum of the polynomial is %d\n", sum);
}

