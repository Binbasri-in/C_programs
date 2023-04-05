// 2. a program to implement a stack using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// global
int s[MAX];
int top = -1;

// prototypes
void push(int item);
void pop();
void is_overflow_or_underflow();
void display();

void main()
{
    int item, ch;

    for(;;)
    {
        printf("1.push  2.pop  3.check status  4. display  5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter item to push: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: is_overflow_or_underflow();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
        }
    }
}

void push(int item)
{
    if (top == MAX-1) // check overflow condition
    {
        printf("Stack Overflow\n");
        return;
    }

    top = top + 1; // push to the stack
    s[top] = item;
}

void pop()
{
    if (top == -1) // check underflow condition
    {
        printf("Stack Underflow\n");
        return;
    }

    
    printf("Poped: %d\n", s[top]); // print the poped item
    top = top - 1; // pop it
}

void is_overflow_or_underflow()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else if (top == MAX-1)
        printf("Stack Overflow\n");
    else
        printf("Not Underflow nor Overflow\n");
}

void display()
{
    int i;

    if (top == -1) // check underflow condition
    {
        printf("Stack is empty\n");
        return;
    }

    printf("The stack is: ");
    for (i = 0; i <= top; i++)
        printf("%d\t", s[i]);
    printf("\n");

}



