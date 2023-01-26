// 3.9 Recursive program to find the GCD of two numbers
// Path: 21CS32_programs\3_recursion9.c
#include <stdio.h>

// prototypes
int gcd(int a, int b);

// main function
int main()
{
    // read the numbers
    int a, b, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // calculate the GCD
    result = gcd(a, b);
    // print the result
    printf("GCD of %d and %d is %d\n", a, b, result);
}

// gcd function
int gcd(int a, int b)
{
    // termination condition
    if (a == b)
        return a;
    // recursive call
    if (a > b)
        return gcd(a-b, b);
    else
        return gcd(a, b-a);
}