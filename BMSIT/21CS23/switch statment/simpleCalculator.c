#include <stdio.h>

int main(void)
{
    float a, b, result;
    int choice;
    printf("Enter 2 numbers\n");
    scanf("%f %f", &a, &b);
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice (only the number)\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        result = a + b;
        break;
    case 2:
        result = a - b;
        break;
    case 3:
        result = a * b;
        break;
    case 4:
        if (b != 0)
            result = a / b;
        else
        {
            printf("Invalid operation.\n");
            return 2;
        }
        break;
    default:
        printf("Invalid operation.\n");
        return 1;
    }
    printf("Result: %f\n", result);

    return 0;
}