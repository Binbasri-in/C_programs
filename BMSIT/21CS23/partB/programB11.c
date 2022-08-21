/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B11- An electricity board charges the following rates for the use of electricity: for the 
first 200 units 80 paise per unit: for the next 100 units 90 paise per unit: beyond 
300 units Rs 1 per unit. All users are charged a minimum of Rs. 100 as meter 
charge. If the total amount is more than Rs 400, then an additional surcharge of 
15% of total amount is charged. Write a program to read the name of the user, 
number of units consumed and print out the charges.

input: User Name, units consumed
output: the total charge of the bill
*/
#include <stdio.h>

int main(void)
{
    int units;
    char name[30];
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
        charges = 100 + 200*0.8 + 300*0.9 + (units-300);
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
