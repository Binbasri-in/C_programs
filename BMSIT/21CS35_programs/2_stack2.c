// 2.2 Implementation of stacks using dynamic arrays (by doubling the size of the array when the array is full)
// Path: 21CS32_programs\2_stacks2.c
#include<stdio.h>
#include<stdlib.h>

int capasity = 5; // initial capasity of the stack

// prototypes
void push(int item, int *top, int *stack);
void pop(int *top, int *stack);
void display(int top, int *stack);

int main()
{
    int *stack = (int *)malloc(capasity * sizeof(int)); // dynamically allocated array
    int top = -1; // initially the stack is empty
    int item;
    int choice;
    while (1)
    {
        // the menu
        printf("1. Push\t2. Pop\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // read the item and push it
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item, &top, stack);
            break;
        case 2:
            pop(&top, stack);
            break;
        case 3:
            display(top, stack);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}

// function to push an item into the stack
void push(int item, int *top, int *stack)
{
    if (*top == capasity - 1)
    {
        // the stack is full
        // double the size of the stack
        capasity *= 2;
        stack = (int *)realloc(stack, capasity * sizeof(int));
    }
    *top += 1;
    stack[*top] = item;
}

// function to pop an item from the stack
void pop(int *top, int *stack)
{
    if (*top == -1)
    {
        // the stack is underflow
        printf("Stack underflow!\n");
        return;
    }
    printf("The popped item is %d\n", stack[*top]);
    *top -= 1;
}

// function to display the stack
void display(int top, int *stack)
{
    if (top == -1)
    {
        // the stack is empty
        printf("The stack is empty!\n");
        return;
    }
    printf("The stack is: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
