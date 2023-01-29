// 3.7 Recursive program for Fibonacci number (find the nth Fibonacci number)
// Path: 21CS32_programs\3_recursion7.c
#include <stdio.h>

// prototypes
int fibonacci(int n);

// main function
int main()
{
    // read the number
    int n, fib;
    printf("Enter a number: ");
    scanf("%d", &n);
    // calculate the fibonacci number
    fib = fibonacci(n);
    // print the result
    printf("Fibonacci number of %d is %d\n", n, fib);
}

// fibonacci function
int fibonacci(int n)
{
    // termination condition when it reaches 0
    if (n == 1)
        return 0;
    // termination condition when it reaches 1
    if (n == 2)
        return 1;
    // recursive call
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Output:
// Enter a number: 5
// Fibonacci number of 5 is 3