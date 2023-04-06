// 3. infix to postfix

#include <stdio.h>
#include <string.h>
#define MAX 30

// prototypes
int input_prec(char symbol);
int stack_prec(char symbol);
void infix_to_postfix(char infix[], char postfix[]);

void main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression(only single digits and no spaces): ");
    scanf("%s", &infix);
    infix_to_postfix(infix, postfix);
    printf("The postfix is: %s\n", postfix);
}

int input_prec(char symbol)
{
    switch(symbol)
    {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 3;
        case '^': case '$': return 6;
        case '(': return '9';
        case ')': return 0;
        default: return 7;

    }
}

int stack_prec(char symbol)
{
    switch(symbol)
    {
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 4;
        case '^': case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    char s[MAX], symbol;
    int n = 0, top = 0, i, len;
    s[0] = '#'; // add # as initial in stack and top is already 0

    for(i=0;infix[i]!='\0';i++) // iterate through the string till termiator
    {
        symbol = infix[i];
        while (input_prec(symbol) < stack_prec(s[top])) // while input precedent of symbol is less than stack precedent of stack top
            postfix[n++] = s[top--]; // pop from stack to postfix

        if (input_prec(symbol) != stack_prec(s[top])) // else if they are not equal push to stack
            s[++top] = symbol;
        else  // if equal ignor them this for ()
            top--;
    }

    while (s[top] != '#') // pop the remaining elements if any
        postfix[n++] = s[top--];
    
    postfix[n] = '\0';
}
