#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int m = a, n = b;
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    printf("GCD of %d and %d is %d\n", a, b, m);
    printf("LCM of %d and %d is %d\n", a, b, (a * b) / m);

    return 0;
}