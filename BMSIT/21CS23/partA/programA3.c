/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A3- develop a program to find the roots of quadrtic equation with proper messages

input: the coefficients a,b and c of quadrestic equation
method: find the distenct and determine the roots
output: type of roots and the roots
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c, disc, root1, root2, real, img;
	
	printf("Enter the a, b, c or quadretic equation\n");
	if (scanf("%f %f %f", &a, &b, &c) != 3)
	{
		printf("invalid input\n");
		return 1;
	}
	
	disc = b*b - 4*a*c;
	if (disc == 0)
	{
		printf("Roots are real and equal\n");
		root1 = root2 = -b / (2*a);
		printf("root1 = %f , root2 = %f\n", root1, root2);
	}
	else if (disc > 0)
	{
		printf("Roots are real and distinct\n");
		root1 = (-b + sqrt(disc)) / (2*a);
		root2 = (-b - sqrt(disc)) / (2*a);
		printf("root1 = %f , root2 = %f\n", root1, root2);
	}
	else
	{
		printf("Roots are imaginary\n");
		real = -b / (2*a);
		img = sqrt(-disc) / (2*a);
		printf("root1 = %f + i%f , root2 = %f - i%f\n", real, img, real, img);
	}
	
	return 0;
}




