#include <stdio.h>

int main()
{
    int n;
    int even_sum = 0, odd_sum = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            even_sum += i;
        }
        else
        {
            odd_sum += i;
        }
    }
    printf("Even sum: %d\n", even_sum);
    printf("Odd sum: %d\n", odd_sum);

    return 0;
}