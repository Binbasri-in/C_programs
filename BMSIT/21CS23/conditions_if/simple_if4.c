#include <stdio.h>

int main(void)
{
    int n1, n2;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &n1, &n2) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (n1 > n2)
    {
        printf("%d is greater than %d.\n", n1, n2);
        return 0;
    }
    if (n1 < n2)
    {
        printf("%d is greater than %d.\n", n2, n1);
        return 0;
    }
    printf("%d is equal to %d.\n", n1, n2);
    return 0;
}