#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (num > 0)
    {
        printf("%d is positive.\n", num);
        return 0;
    }
    if (num < 0)
    {
        printf("%d is negative.\n", num);
        return 0;
    }
    printf("%d is zero.\n", num);
    return 0;
}