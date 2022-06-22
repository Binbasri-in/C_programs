#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    double start = get_double("Start Size: ");
    while (start < 9)
    {
        start = get_double("Start Size: ");
    }

    // TODO: Prompt for end size
    double end = get_double("End Size: ");
    while (end < start)
    {
        end = get_double("End Size:");
    }

    // TODO: Calculate number of years until we reach threshold

    int n = 0;
    while (true)
    {
        double rate = (start / 3) - (start / 4);
        if (start == end)
        {
            break;
        }
        if (start < end)
        {
            n += 1;
            start += rate;
        }
        else
        {
            break;
        }

    }

    // TODO: Print number of years
    printf("Years: %i \n", n);
}