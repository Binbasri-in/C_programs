// 2. a program to implement a stack using array
#include<stdio.h>
#include<stdlib.h>
#define stack_size 100

// prototype of the functions
void push(int item, int *top,int s[]);
void pop(int *top,int s[]);
void display(int *top,int s[]);
void is_empty(int *top);
void is_full(int *top);

int main()
{
    // initialize the stack
    int stack[stack_size],top=-1;
    // initialize the variable to store the choice
    int choice;
    // initialize the variable to store the item
    int item;
    // iterate through the menu
    while(1)
    {
        // display the menu
        printf("1. Push an element to the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display the stack\n");
        printf("4. Check if the stack is empty\n");
        printf("5. Check if the stack is full\n");
        printf("6. Exit\n");
        // get the choice
        printf("Enter your choice: ");
        scanf("%d",&choice);
        // perform the operation based on the choice
        switch(choice)
        {
            case 1:
                // get the item
                printf("Enter the item: ");
                scanf("%d",&item);
                // push the item to the stack
                push(item,&top,stack);
                break;
            case 2:
                // pop the item from the stack
                pop(&top,stack);
                break;
            case 3:
                // display the stack
                display(&top,stack);
                break;
            case 4:
                // check if the stack is empty
                is_empty(&top);
                break;
            case 5:
                // check if the stack is full
                is_full(&top);
                break;
            case 6:
                // exit the program
                exit(0);
            default:
                // display the error message
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(int item, int *top,int s[])
{
    // check if the stack is full
    if(*top==stack_size-1)
    {
        // display the error message
        printf("Stack overflow\n");
        return;
    }
    // increment the top
    (*top)++;
    // push the item to the stack
    s[*top]=item;
}

void pop(int *top,int s[])
{
    // check if the stack is empty
    if(*top==-1)
    {
        // display the error message
        printf("Stack underflow\n");
        return;
    }
    // display the popped item
    printf("The popped item is: %d\n",s[*top]);
    // decrement the top
    (*top)--;
}

void display(int *top,int s[])
{
    // check if the stack is empty
    if(*top==-1)
    {
        // display the error message
        printf("Stack is empty\n");
        return;
    }
    // display the stack
    printf("The stack is: ");
    for (int i = *top; i >=0; i--)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}

void is_empty(int *top)
{
    // check if the stack is empty
    if(*top==-1)
    {
        // display the message
        printf("Stack is empty\n");
    }
    else
    {
        // display the message
        printf("Stack is not empty\n");
    }
}

void is_full(int *top)
{
    // check if the stack is full
    if(*top==stack_size-1)
    {
        // display the message
        printf("Stack is full\n");
    }
    else
    {
        // display the message
        printf("Stack is not full\n");
    }
}


