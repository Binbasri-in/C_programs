// 4. a program to evaluate a postfix expression using stack
#include<stdio.h>
#include<math.h>
#define stack_size 100

// prototype of the functions
void push(int item, int *top,int s[]);
int pop(int *top,int s[]);
int evaluate_postfix(char postfix[]);

int main()
{
    // initialize the string to store the postfix expression
    char postfix[stack_size];
    // get the postfix expression
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    // evaluate the postfix expression
    printf("The value of the postfix expression is: %d",evaluate_postfix(postfix));
    return 0;
}

int evaluate_postfix(char postfix[])
{
    // initialize the stack
    int stack[stack_size],top=-1;
    // initialize the variables to store the operands
    int operand1,operand2, symbol;
    // initialize the variable to store the result
    int result;
    // iterate through the postfix expression
    for (int i = 0; postfix[i]!='\0'; i++)
    {
        // get the symbol from the postfix expression
        symbol=postfix[i];
        // evaluate the expression if operator or store it if operand
        switch(symbol)
        {
            case '+':
                operand2=pop(&top,stack);
                operand1=pop(&top,stack);
                result=operand1+operand2;
                push(result,&top,stack);
                break;
            case '-':
                operand2=pop(&top,stack);
                operand1=pop(&top,stack);
                result=operand1-operand2;
                push(result,&top,stack);
                break;
            case '*':
                operand2=pop(&top,stack);
                operand1=pop(&top,stack);
                result=operand1*operand2;
                push(result,&top,stack);
                break;
            case '/':
                operand2=pop(&top,stack);
                operand1=pop(&top,stack);
                result=operand1/operand2;
                push(result,&top,stack);
                break;
            case '^':
                operand2=pop(&top,stack);
                operand1=pop(&top,stack);
                result=(int)pow((double)operand1,(double)operand2);
                push(result,&top,stack);
                break;
            default:
                // convert the character to integer and store it in the stack
                push(symbol-'0',&top,stack);
                break;
        }
    }
    return pop(&top,stack);
}

void push(int item, int *top,int s[])
{
    // check if the stack is full
    if(*top==stack_size-1)
        printf("Stack overflow");
    else
    {
        // increment the top of the stack
        *top=*top+1;
        // add the item to the stack
        s[*top]=item;
    }
}

int pop(int *top,int s[])
{
    // check if the stack is empty
    if(*top==-1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        // get the item from the stack
        int item=s[*top];
        // decrement the top of the stack
        *top=*top-1;
        // return the item
        return item;
    }
}
