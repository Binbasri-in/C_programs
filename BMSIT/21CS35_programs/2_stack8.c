// 2.8 program to check whether a given string is a palindrome or not using stacks
// Path: 21CS32_programs\2_stack8.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 50

// prototypes
void push(char item, int *top, char s[]);
char pop(int *top, char s[]);
int check_palindrome(char s[]);

void main()
{
    // read input from user
    char s[stacksize];
    printf("Enter the string: ");
    scanf("%s", s);
    // check if the string is a palindrome
    if (check_palindrome(s))
    {
        printf("The string is a palindrome\n");
    }
    else
    {
        printf("The string is not a palindrome\n");
    }
}

// a function to check if the string is a palindrome
int check_palindrome(char s[])
{
    int i, n, top = -1;
    // a stack to store the reversed string
    char rev[stacksize];
    n = strlen(s);
    // push the string to the stack
    for (i = 0; i < n; i++)
    {
        push(s[i], &top, rev);
    }
    // for each char
    for (i = 0; i < n; i++)
    {
        // check if the char is equal to the popped char from the reverse stack
        if (s[i] != pop(&top, rev))
        {
            // if found a character that is not equal, return 0
            return 0;
        }
    }
    // if all characters are equal, return 1
    return 1;
}

// a function to push an item to the stack
void push(char item, int *top, char s[])
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
char pop(int *top, char s[])
{
    char item;
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    item = s[*top];
    *top = *top - 1;
    return item;
}