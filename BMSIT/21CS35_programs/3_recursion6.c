// 3.6 Recursive program to find the factorial of a number
// Path: 21CS32_programs\3_recursion6.c
#include <stdio.h>

// prototypes
int factorial(int n);

// main function
int main()
{
    // read the number
    int n, fact;
    printf("Enter a number: ");
    scanf("%d", &n);
    // calculate the factorial
    fact = factorial(n);
    // print the result
    printf("Factorial of %d is %d\n", n, fact);
}

// factorial function
int factorial(int n)
{
    // termination condition when it reaches 0
    if (n == 0)
        return 1;
    // recursive call
    return n * factorial(n - 1);
}