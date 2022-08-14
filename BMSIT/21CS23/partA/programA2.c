/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A2- develop a program to simulate the operations of simple calculator

input: 2 operands and one operator in the form ( 13 + 123 )
method: using switch statement to choose the operation
output: the result after making the operation
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float n1, n2, res;
	char op;
	printf("Enter the expression ( 12 + 123 ) only support(+,-,*,/,%%(remainder))\n");
	if (scanf("%f %c %f", &n1, &op, &n2) != 3 || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'))
	{
		printf("Expression is not correct\n");
		return 1;
	}
	
	switch (op)
	{
		case '+': res = n1 + n2; break;
		case '-': res = n1 - n2; break;
		case '*': res = n1 * n2; break;
		case '/':if (n2 == 0)
			{
				printf("Error: Division by zero\n");
				return 2;
			}
			res = n1 /  n2; break;
		case '%': res = (int)n1 % (int)n2; break;
	}
	printf("%f\t%c\t%f\t=\t%f\n", n1, op, n2, res);
	
	return EXIT_SUCCESS;
}
