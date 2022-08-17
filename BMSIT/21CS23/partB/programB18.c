/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B18- Design, develop and execute a C program to compute sin(x) using Taylor series 
approximation. Compare your result with the built-in library function. Print both 
the results with appropriate inferences. 

input: The value of x
method: Taylor series approximation
output: The value of sin(x)
*/
#include <stdio.h>

double sin(double x);
double sin_builtin(double x);



int main()
{
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("The value of sin(x) using Taylor series approximation is: %lf\n", sin(x));
    printf("The value of sin(x) using built-in library function is: %lf\n", sin_builtin(x));
}


double sin(double x)
{
    double sum = 0, fact = 1, x_power = x;
    for (int i = 1; i <= 10; i++)
    {
        sum += (x_power / fact);
        x_power *= -x * x;
        fact *= (2 * i + 1) * (2 * i + 2);
    }
    return sum;
}

double sin_builtin(double x)
{
    return sin(x);
}



