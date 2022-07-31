#include <stdio.h>

int main(void)
{
    int n;
    int factorial = 1;
    printf("Enter the number: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n)
    {
        factorial *= i;
        i++;
    }
    printf("Factorial of the number %d is: %d\n", n, factorial);

    return 0;
}