#include <stdio.h>

int main()
{
    int n, p=0, q=1, r;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n == 1)
        printf("%d\n", p);
    else if (n == 2)
        printf("%d\t%d\n", p, q);
    else
    {
        printf("%d\t%d\t", p, q);
        for (int i = 3; i <= n; i++)
        {
            r = p + q;
            p = q;
            q = r;
            printf("%d\t", r);
        }
    }
    return 0;
}