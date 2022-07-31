#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, x;
    int sum = 0;
    printf("Enter the number x\n");
    scanf("%d", &x);
    printf("Enter the number n\n");
    scanf("%d", &n);

    int i = 1;
    while (i <= n)
    {
        sum += pow(x, i);
        i++;
    }
    printf("The sum of the series: %d\n", sum);

    return 0;
}