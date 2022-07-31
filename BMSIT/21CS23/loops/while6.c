#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int i = 0;
    while (i < n)
    {
        printf("%d ", n-i);
        i++;
    }
    
    return 0;
}