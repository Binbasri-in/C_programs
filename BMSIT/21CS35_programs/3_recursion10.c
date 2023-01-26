// 3.10 Recursive program to find Binomial Coefficient (nCr)
// Path: 21CS32_programs\3_recursion10.c
#include <stdio.h>

// prototypes
int binomial(int n, int r);

// main function
int main()
{
    // read the numbers
    int n, r, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &r);
    // calculate the binomial coefficient
    result = binomial(n, r);
    // print the result
    printf("Binomial coefficient of %d and %d is %d\n", n, r, result);
}

// binomial function
int binomial(int n, int r)
{
    // termination condition
    if (r == 0 || r == n)
        return 1;
    // recursive call
    return binomial(n - 1, r - 1) + binomial(n - 1, r);
}