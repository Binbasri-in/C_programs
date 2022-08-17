/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: B11- 

input: User Name, units consumed
output: the total charge of the bill
*/
#include <stdio.h>

int main(void)
{
    int units;
    char name[20];
    float charges;

    printf("Enter your name: ");
    scanf("%[^\n]", name);
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);
    
    if (units < 0)
    {
        printf("Invalid number of units cosumed.\n");
        return 1;
    }
    else if (units == 0)
    {
        charges = 100;
    }
    else if (units > 0 && units <=200)
    {
        charges = 100 + units*0.8;
    }
    else if (units > 200 && units <=300)
    {
        charges = 100 + 200*0.8 + (units-200)*0.9;
    }
    else if (units > 300)
    {
        charges = 100 + 200*0.8 + 300*1.5 + (units-300)*1;
    }
    
    if (charges > 400)
    {
        charges = charges + charges*0.15;
    }

    printf("Name of the consumer: %s\n", name);
    printf("Number of units consumed: %d\n", units);
    printf("Charges: %.2f\n", charges);

    return 0;
}
