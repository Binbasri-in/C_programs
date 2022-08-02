#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i+=2)
    {
        printf("%d\t", i);
    }
    return 0;
}