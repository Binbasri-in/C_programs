#include <stdio.h>

int main(void)
{
    int n;
    int factorial = 1;
    printf("Enter the number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    printf("Factorial of the number %d is: %d\n", n, factorial);

    return 0;
}