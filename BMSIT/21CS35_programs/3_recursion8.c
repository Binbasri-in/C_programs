// 3.8 Recursive program for Fibonacci number (generate n Fibonacci numbers)
// Path: 21CS32_programs\3_recursion8.c
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
    for (int i = 0; i < n; i++)
    {
        fib = fibonacci(i);
        printf("%d ", fib);
    }
    printf("\n");
}


// fibonacci function
int fibonacci(int n)
{
    // termination condition when it reaches 0
    if (n == 0)
        return 0;
    // termination condition when it reaches 1
    if (n == 1)
        return 1;
    // recursive call
    return fibonacci(n - 1) + fibonacci(n - 2);
}