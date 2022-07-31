#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a non-zero number: ");
    if (scanf("%d", &num) != 1 || num == 0)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (num > 0)
        printf("%d is positive.\n", num);
    else
        printf("%d is negative.\n", num);

    return 0;
}