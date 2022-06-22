#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change Owed: ");
    }
    while (change < 0);
    int cents = round(change * 100);
    int coins = 0;
    while (cents != 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
            continue;
        }
        if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
            continue;
        }
        if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
            continue;
        }
        if (cents >= 1)
        {
            cents = cents - 1;
            coins++;
            continue;
        }
    }
    printf("%i\n", coins);
}