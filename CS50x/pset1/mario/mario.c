#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int level;
    do
    {
        level = get_int("Hight: ");
    }
    while (level < 1 || level > 8);

    for (int i = 0; i < level; i++)
    {
        for (int j = level - 1; j > i ; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}