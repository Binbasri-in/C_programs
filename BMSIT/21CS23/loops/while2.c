#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0;
    printf("Enter the number: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n)
    {
        sum += i;
        i++;
    }
    printf("Sum of the numbers: %d\n",sum);
    
    return 0;
}