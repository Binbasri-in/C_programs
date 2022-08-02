#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    double x = 0.000001;
    while (x * x < n)
    {
        x += 0.000001;
    }
    printf("Square root of %d is %f\n", n, x);

    return 0;
}