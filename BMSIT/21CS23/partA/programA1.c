/* 
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A1- develop a program to find the biggest of three numbers using ternirary operator

input: three numbers
method: compare the numbers using terniray operators
output: the biggest amoung three numbers
*/
#include <stdio.h>

int main()
{
	int n1, n2, n3, max;
	printf("Enter three numbers\n");
	if (scanf("%d %d %d", &n1, &n2, &n3) != 3)
	{
		printf("invaild inpur\n");
		return 1;
	}
	
	max = n1 > n2 ? n1 : n2;
	max = max > n3 ? max : n3;
	// max = n1 > n2 ? (n1 > n3 ? n1: n3) : (n2 > n3 ? n2 : n3);
	
	printf("The biggest number is %d\n", max);
	
	return 0;
}
