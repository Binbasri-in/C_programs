/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A6- develop a c program to display fibonacci sequence

input: number of numbers to be displayed
method: find fibonacci sequence till the givin order
output: fibonacci seq till the nth order
*/
#include <stdio.h>

int main()
{
    int n;
    double p=0, q=1, r;
    printf("Enter a positive number: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("invalid input\n");
        return 1;
    }
    if (n == 1)
        printf("%.1f", p);
    else if (n == 2)
        printf("%.1f\t%.1f", p, q);
    else
    {
        printf("%.1f\t%.1f\t", p, q);
        for (int i = 3; i <= n; i++)
        {
            r = p + q;
            p = q;
            q = r;
            printf("%.1f\t", r);
        }
    }
    printf("\n");
    return 0;
}
