// 4. a program to evaluate a postfix expression using stack
// 4. evaluation of postfix expressions

#include <stdio.h>
#include <math.h> // remember to add -lm in the compilation (gcc file.c -lm)
#define MAX 20

//prototypes
int eval_post(char exp[]);

void main()
{
    char postfix[MAX];

    printf("Enter postfix exp (No spaces and single digit operands): ");
    scanf("%s", postfix);
    printf("The result: %d\n", eval_post(postfix));
}

int eval_post(char exp[])
{
    int s[MAX], top = -1, i, op1, op2;
    char symbol;

    for (i = 0; exp[i] != '\0'; i++)
    {
        symbol = exp[i];

        switch(symbol)
        {
            case '+': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = op1 + op2;
                      break;
            case '-': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = op1 - op2;
                      break;
            case '*': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = op1 * op2;
                      break;
            case '/': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = op1 / op2;
                      break;
            case '%': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = op1 % op2;
                      break;
            case '^': op2 = s[top--];
                      op1 = s[top--];
                      s[++top] = (int)pow((double)op1,(double)op2);
                      break;
            default: s[++top] = symbol - '0';
        }
    }

    return s[top];
}
