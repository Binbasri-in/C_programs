#include <stdio.h>

int main(void)
{
    int n1, n2, n3;
    printf("Enter three numbers: ");
    if (scanf("%d %d %d", &n1, &n2, &n3) != 3)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (n1 > n2 && n1 > n3)
    {
        printf("%d is the largest.\n", n1);
        return 0;
    }
    if (n2 > n3)
    {
        printf("%d is the largest.\n", n2);
        return 0;
    }
    printf("%d is the largest.\n", n3);
    return 0;
}