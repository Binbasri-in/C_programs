// 3.12 Recursive program for Ackerman's function
// Path: 21CS32_programs\3_recursion12.c
#include <stdio.h>

// prototypes
int ackerman(int m, int n);

// main function
int main()
{
    // read the numbers
    int m, n, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);
    // calculate the result
    result = ackerman(m, n);
    // print the result
    printf("Ackerman's function of %d and %d is %d\n", m, n, result);
}

// ackerman function
int ackerman(int m, int n)
{
    // termination condition
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ackerman(m - 1, 1);
    // recursive call
    return ackerman(m - 1, ackerman(m, n - 1));
}

// Output:
// Enter two numbers: 1 2
// Ackerman's function of 1 and 2 is 4
// Enter two numbers: 3 3
// Ackerman's function of 3 and 3 is 61
