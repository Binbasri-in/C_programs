// 3. Write a program to convert an infix expression to postfix expression.
#include <stdio.h>
#define stack_size 100

int input_precedence(char);
int stack_precedence(char);
void push(char item, int *top,char s[]);
char pop(int *top,char s[]);
void infix_postfix(char infix[],char postfix[]);

int main()
{
    // initialize the strings to store the expressions
    char infix[stack_size],postfix[stack_size];
    // get the infix expression
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    // convert the infix expression to postfix expression
    infix_postfix(infix,postfix);
    // print the postfix expression
    printf("The postfix expression is: %s",postfix);
    return 0;
}

void infix_postfix(char infix[],char postfix[])
{
    // initialize the stack
    char stack[stack_size],symbol;
    // initialize the top of the stack
    int i,top=0,j=0;
    // push the # symbol to the stack to indicate the end of the stack
    stack[0]='#';
    // iterate through the infix expression
    for(i=0;infix[i]!='\0';i++)
    {
        // get the symbol from the infix expression
        symbol=infix[i];
        // if the symbol is an operand, add it to the postfix expression
        while(stack_precedence(stack[top])>input_precedence(symbol))
        {
            postfix[j]=pop(&top,stack);
            j++;
        }
        // if the symbol is an operator, push it to the stack
        if(stack_precedence(stack[top])!=input_precedence(symbol))
            // push the symbol to the stack
            push(symbol,&top,stack);
        else
            // pop the symbol from the stack if it is a closing bracket
            pop(&top,stack);
    }
    // pop the remaining symbols from the stack
    while(stack[top]!='#')
    {
        postfix[j]=pop(&top,stack);
        j++;
    }
    // add the null character to the end of the postfix expression
    postfix[j]='\0';
}

// function to return the precedence of the input symbol
int input_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
        case '$':
            return 6;
        case '(': return 9;
        case ')': return 0;
        default:
            return 7;
    }
}

// function to return the precedence of the stack symbol
int stack_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 4;
        case '^':
        case '$':
            return 5;
        case '(': return 0;
        case '#': return -1;
        default:
            return 8;
    }
}

// function to push an item to the stack
void push(char item, int *top,char s[])
{
    // check if the stack is full
    if(*top==stack_size-1)
    {
        printf("Stack Overflow");
        return;
    }
    // increment the top of the stack
    *top=*top+1;
    // push the item to the stack
    s[*top]=item;
}

// function to pop an item from the stack
char pop(int *top,char s[])
{
    char item;
    // check if the stack is empty
    if(*top==-1)
    {
        printf("Stack Underflow");
        return -1;
    }
    // pop the item from the stack
    item=s[*top];
    // decrement the top of the stack
    *top=*top-1;
    // return the item
    return item;
}