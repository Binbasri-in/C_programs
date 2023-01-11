// 2.3 converting infix to postfix for single digit operands
// path: 21CS32_programs\2_stack3.c
// infix: 2+3*4
// postfix: 234*+
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 70

// prototypes
int input_precedence(char ch);
int stack_precedence(char ch);
void infix_to_postfix(char infix[], char postfix[]);
void push(char ch, int *top, char stack[]);
char pop(int *top, char stack[]);

void main()
{
    // initialize the the expressions
    char infix[stacksize], postfix[stacksize];

    // read the infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // convert the infix expression to postfix
    infix_to_postfix(infix, postfix);

    // display the postfix expression
    printf("The postfix expression is: %s\n", postfix);
}

// function to give the input precedence of an operator
int input_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 3;
    case '^':
    case '$': return 6;
    case '(': return 9;
    case ')': return 0;
    default: return 7;
    }
}

// function to give the stack precedence of an operator
int stack_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-': return 2;
    case '*':
    case '/':
    case '%': return 4;
    case '^':
    case '$': return 5;
    case '(': return 0;
    case '#': return -1;
    default: return 8;
    }
}

// function to convert infix to postfix
void infix_to_postfix(char infix[], char postfix[])
{
    // declare the variables and initialize them
    int i, n, j, top;
    char ch, stack[stacksize];
    j = 0;
    top = -1;
    n = strlen(infix);
    push('#', &top, stack);

    // convert the infix expression to postfix
    for (i=0;i<n;i++)
    {
        symbol = infix[i];
        while (stack_precedence(stack[top]) > input_precedence(symbol))
        {
            postfix[j] = pop(&top, stack);
            j++;
        }
        if (stack_precedence(stack[top]) != input_precedence(symbol))
        {
            push(symbol, &top, stack);
        }
        else
        {
            pop(&top, stack);
        }
    }
    while (stack[top] != '#')
    {
        postfix[j] = pop(&top, stack);
        j++;
    }
    postfix[j] = '\0';
}

// function to push an item into the stack
void push(char ch, int *top, char stack[])
{
    // check for overflow
    if (*top == stacksize - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    *top += 1;
    stack[*top] = ch;
}

// function to pop an item from the stack
char pop(int *top, char stack[])
{
    // check for underflow
    if (*top == -1)
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    char ch = stack[*top];
    *top -= 1;
    return ch;
}

