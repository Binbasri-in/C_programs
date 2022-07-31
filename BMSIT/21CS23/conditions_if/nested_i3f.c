#include <stdio.h>

int main(void)
{
    float a,b,result;
    char op;

    printf("Enter the exprestion (13 + 12): \n");
    if (scanf("%f %c %f", &a, &op, &b) != 3 || op != '+' && op != '-' && op != '*' && op != '/')
    {
        printf("Invalid operation.\n");
        return 1;
    }
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else
    {
        if (b != 0)
            result = a / b;
        else
        {
            printf("Invalid operation.\n");
            return 2;
        }
    }
    
    printf("Result: %f\n", result);
    return 0;
}