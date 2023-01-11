// 2.5 a program to divide an array into multiple stacks
// path: 21CS32_programs\2_stack5.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 70
#define maxstacks 10

// global variables
int n; // number of stacks
int top[maxstacks]; // top of each stack
int bound[maxstacks]; // upper bound of each stack
int stack[stacksize]; // the array that contains the stacks

// prototypes
void push(int item, int stackno);
void pop(int stackno);
void display(int stackno);

void main()
{
    // 
    int i,choice, item, stackno;

    // read number of stacks
    printf("Enter the number of stacks: ");
    scanf("%d", &n);
    // initialize the top and boundary of each stack
    for (i = 0; i < n; i++)
    {
        top[i] = bound[i] = stacksize / n * i - 1;
    }
    
    // the menu
    for(;;)
    {
        printf("1.push to. 2.pop from. 3.display. 4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the stack number: ");
                    scanf("%d", &stackno);
                    printf("Enter the item to be pushed: ");
                    scanf("%d", &item);
                    push(item, stackno);
                    break;
            case 2: printf("Enter the stack number: ");
                    scanf("%d", &stackno);
                    pop(stackno);
                    break;
            case 3: printf("Enter the stack number: ");
                    scanf("%d", &stackno);
                    display(stackno);
                    break;
            case 4: exit(0);
        }
    }
}

// function to push an item into a stack
void push(int item, int stackno)
{
    if (top[stackno] == bound[stackno + 1])
    {
        printf("Stack overflow\n");
        return;
    }
    top[stackno]++;
    stack[top[stackno]] = item;
}

// function to pop an item from a stack
void pop(int stackno)
{
    if (top[stackno] == bound[stackno])
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The popped item is: %d\n", stack[top[stackno]]);
    top[stackno]--;
}

// function to display the contents of a stack
void display(int stackno)
{
    int i;
    if (top[stackno] == bound[stackno])
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The contents of the stack are: ");
    for (i = top[stackno]; i > bound[stackno]; i--)
        printf("%d ", stack[i]);
    printf("\n");
}