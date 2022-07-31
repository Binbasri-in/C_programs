#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int i = 2;
    while (i <= n)
    {
        printf("%d ", i);
        i += 2;
    }
    
    return 0;
}