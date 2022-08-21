/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A10- develop a c program tofind a key in an array of size n using linear search

input: an element "a number"
method: iterate through the array looking for a match
output: the position if found or simply print not found
*/
#include <stdio.h>

int main(void)
{
	int n, key;
	
	printf("Enter the number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0)
	{
		printf("Invalid size of array\n");
		return 1;
	}
	int a[n];
	printf("Enter the elements one by one:\n");
	for (int i = 0; i < n; i++)
		if (scanf("%d", &a[i]) != 1)
		{
			printf("Invalid input\n");
			return 2;
		}
		
	printf("Enter the key to be found: ");
	scanf("%d", &key);
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			printf("The number %d is found at position %d\n", key, i+1);
			return 0;
		}
	}
	
	printf("Not found!!\n");
	return 0;
}


