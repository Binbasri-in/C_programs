// 2.4 a program to evaluate postfix expression
// path: 21CS32_programs\2_stack4.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 70

// prototypes
void push(int item, int *top, int stack[]);
int pop(int *top, int stack[]);
int evaluate_postfix(char postfix[]);

int main()
{
    // initialize the the expressions
    char postfix[stacksize];
    int result;

    // read the postfix expression
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    // evaluate the postfix expression
    result = evaluate_postfix(postfix);

    // display the result
    printf("The result is: %d\n", result);
}

// function to evaluate the postfix expression
int evaluate_postfix(char postfix[])
{
    int i, n, op1, op2, res, top, stack[stacksize];
    char symbol;
    n = strlen(postfix);
    top = -1;
    for (i=0; i<n; i++)
    {
        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
            push(symbol -'0', &top, stack);
        else
        {
            op2 = pop(&top, stack);
            op1 = pop(&top, stack);
            switch (symbol)
            {
                case '+': res = op1 + op2;
                          break;
                case '-': res = op1 - op2;
                          break;
                case '*': res = op1 * op2;
                          break;
                case '/': res = op1 / op2;
                          break;
            }
            push(res, &top, stack);
        }
    }
    return pop(&top, stack);
}

// function to push an item into the stack
void push(int item, int *top, int stack[])
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    *top = *top + 1;
    stack[*top] = item;
}

// function to pop an item from the stack
int pop(int *top, int stack[])
{
    int item;
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    item = stack[*top];
    *top = *top - 1;
    return item;
}