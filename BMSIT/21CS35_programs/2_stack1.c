// 2.1 Implementation of stacks using arrays
// Path: 21CS32_programs\2_stacks1.c
#include<stdio.h>
#include<stdlib.h>

// prototype for the functions
void push(int item, int *top, int stack[]);
int pop(int *top, int stack[]);
void display(int *top, int stack[]);
void isEmpty(int *top);
void isFull(int *top);

int main()
{
    // initialize the stack
    int stack[5];
    // initialize the top variable
    int top=-1;
    // initialize the variable to store the choice
    int choice;
    // iterate through the menu
    for(;;)
    {
        // display the menu
        printf("1. Push\t2. Pop\t3. Display\t4. isEmpty\t5. isFull\t6. Exit\nEnter your choice: ");
        // get the choice
        scanf("%d",&choice);
        // check the choice
        switch(choice)
        {
            // push
            case 1:
            {
                // initialize the variable to store the item to be pushed
                int item;
                // get the item to be pushed
                printf("Enter the item to be pushed: ");
                scanf("%d",&item);
                // push the item
                push(item,&top,stack);
                break;
            }
            // pop
            case 2:
            {
                // pop the item
                int item=pop(&top,stack);
                // check if the item is not -1
                if(item!=-1)
                {
                    // print the item
                    printf("Item popped: %d\n",item);
                }
                break;
            }
            // display
            case 3:
            {
                // display the stack
                display(&top,stack);
                break;
            }
            // isEmpty
            case 4:
            {
                // check if the stack is empty
                isEmpty(&top);
                break;
            }
            // isFull
            case 5:
            {
                // check if the stack is full
                isFull(&top);
                break;
            }
            // exit
            case 6:
            {
                // exit
                exit(0);
            }
            // default
            default:
            {
                // print the message
                printf("Invalid choice\n");
            }
        }
    }
}

// function to push an item to the stack
void push(int item, int *top, int stack[])
{
    // check if the stack is full
    if(*top==4)
    {
        // print the message
        printf("Stack overflow\n");
    }
    // check if the stack is not full
    else
    {
        // increment the top variable
        *top=*top+1;
        // push the item
        stack[*top]=item;
    }
}

// function to pop an item from the stack
int pop(int *top, int stack[])
{
    // check if the stack is empty
    if(*top==-1)
    {
        // print the message
        printf("Stack underflow\n");
        // return -1
        return -1;
    }
    // check if the stack is not empty
    else
    {
        // initialize the variable to store the item to be popped
        int item;
        // pop the item
        item=stack[*top];
        // decrement the top variable
        *top=*top-1;
        // return the item
        return item;
    }
}

// function to display the stack
void display(int *top, int stack[])
{
    // check if the stack is empty
    if(*top==-1)
    {
        // print the message
        printf("Stack is empty\n");
    }
    // check if the stack is not empty
    else
    {
        // initialize the index variable
        int i;
        // iterate through the stack
        for(i=*top; i>=0; i--)
        {
            // print the item
            printf("%d\t",stack[i]);
        }
        // print a new line
        printf("\n");
    }
}

// function to check if the stack is empty
void isEmpty(int *top)
{
    // check if the stack is empty
    if(*top==-1)
    {
        // print the message
        printf("Stack is empty\n");
    }
    // check if the stack is not empty
    else
    {
        // print the message
        printf("Stack is not empty\n");
    }
}

// function to check if the stack is full
void isFull(int *top)
{
    // check if the stack is full
    if(*top==4)
    {
        // print the message
        printf("Stack is full\n");
    }
    // check if the stack is not full
    else
    {
        // print the message
        printf("Stack is not full\n");
    }
}

// Output:
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 1
// Enter the item to be pushed: 10
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 1
// Enter the item to be pushed: 20
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 1
// Enter the item to be pushed: 30
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 3
// 30      20      10
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 2
// Item popped: 30
// 1. Push  2. Pop   3. Display       4. isEmpty       5. isFull        6. Exit
// Enter your choice: 3
// 20      10
        