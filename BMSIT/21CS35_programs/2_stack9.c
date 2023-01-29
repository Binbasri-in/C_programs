// program to check whether a given number is a palindrome or not using stacks
// Path: 21CS32_programs\2_stack9.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 50

// prototypes
void push(int item, int *top, int s[]);
int pop(int *top, int s[]);
int check_palindrome(char num[]);

int main()
{
    // read input from user
    char num[stacksize];
    printf("Enter the number: ");
    scanf("%s", num);
    // check if the number is a palindrome
    if (check_palindrome(num))
    {
        printf("The number is a palindrome\n");
    }
    else
    {
        printf("The number is not a palindrome\n");
    }
}

// a function to check if the number is a palindrome
int check_palindrome(char num[])
{
    int i, n, top = -1;
    // a stack to store the reversed number
    int rev[stacksize];
    n = strlen(num);
    // push the number to the stack
    for (i = 0; i < n; i++)
    {
        push(num[i] - '0', &top, rev);
    }
    // for each digit
    for (i = 0; i < n; i++)
    {
        // check if the digit is equal to the popped digit from the reverse stack
        if (num[i] - '0' != pop(&top, rev))
        {
            // if found a digit that is not equal, return 0
            return 0;
        }
    }
    // if all digits are equal, return 1
    return 1;
}

// a function to push an item to the stack
void push(int item, int *top, int s[])
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    *top = *top + 1;
    s[*top] = item;
}

// a function to pop an item from the stack
int pop(int *top, int s[])
{
    int item;
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    item = s[*top];
    *top = *top - 1;
    return item;
}

// Output:
// Enter the number: 12321
// The number is a palindrome
// Enter the number: 12345
// The number is not a palindrome