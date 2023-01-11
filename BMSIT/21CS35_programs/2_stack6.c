// 2.6 program to implement 2 stacks in a single array
// Path: 21CS32_programs\2_stack6.c
#include<stdio.h>
#include<stdlib.h>

#define stacksize 10

// prototypes
void push1(int item, int *top1, int *top2, int s[]);
void push2(int item, int *top1, int *top2, int s[]);
void pop1(int *top1, int *top2, int s[]);
void pop2(int *top1, int *top2, int s[]);
void display1(int top1, int s[]);
void display2(int top2, int s[]);

int main()
{
    int s[stacksize], top1 = -1, top2 = stacksize;
    int ch, item;
    while(1)
    {
        printf("1.push to stack 1. 2.pop from stack 1. 3.display stack 1\n");
        printf("4.push to stack 2. 5.pop from stack 2. 6.display stack 2\n");
        printf("7.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("Enter the item to be pushed: ");
                    scanf("%d", &item);
                    push1(item, &top1, &top2, s);
                    break;
            case 2: pop1(&top1, &top2, s);
                    break;
            case 3: display1(top1, s);
                    break;
            case 4: printf("Enter the item to be pushed: ");
                    scanf("%d", &item);
                    push2(item, &top1, &top2, s);
                    break;
            case 5: pop2(&top1, &top2, s);
                    break;
            case 6: display2(top2, s);
                    break;
            case 7: exit(0);
        }
    }
}

// push to stack 1
void push1(int item, int *top1, int *top2, int s[])
{
    if (*top1 == *top2 - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

// push to stack 2
void push2(int item, int *top1, int *top2, int s[])
{
    if (*top1 == *top2 - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top2 = *top2 - 1;
    s[*top2] = item;
}

// pop from stack 1
void pop1(int *top1, int *top2, int s[])
{
    if (*top1 == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The popped item is %d\n", s[*top1]);
    *top1 = *top1 - 1;
}

// pop from stack 2
void pop2(int *top1, int *top2, int s[])
{
    if (*top2 == stacksize)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The popped item is %d\n", s[*top2]);
    *top2 = *top2 + 1;
}

// display stack 1
void display1(int top1, int s[])
{
    int i;
    if (top1 == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The stack is: ");
    for (i = 0; i <= top1; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}

// display stack 2
void display2(int top2, int s[])
{
    int i;
    if (top2 == stacksize)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The stack is: ");
    for (i = stacksize - 1; i >= top2; i--)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}