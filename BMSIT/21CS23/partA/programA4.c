/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A4- develope a c program to find GCD and LCM of two numbers using Eulric algorithm

input: two numbers
method: Eulric Algorithm
output: The GCD and The LCM
*/
#include <stdio.h>

int main(void)
{
	int n1, n2, n, m;
	
	printf("Enter two numbers\n");
	if (scanf("%d %d", &n1, &n2) != 2)
	{
		printf("Inputs are Invalid\n");
		return 1;
	}
	
	m = n1;
	n = n2;
	while (m != n)
	{
		if (m > n)
			m -= n;
		else
			n -= m;
	} 
	
	printf("The GCD of %d and %d is %d\n", n1, n2, m);
	if (m == 0)
		printf("The LCM of %d and %d is %d\n", n1, n2, m);
	else
		printf("The LCM of %d and %d is %d\n", n1, n2, (n1*n2)/m);
	
	return 0;
}





