// 2.7 program to reverse a given string using stacks
// Path: 21CS32_programs\2_stack7.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stacksize 50

// prototypes
void push(char item, int *top, char s[]);
char pop(int *top, char s[]);
void reverse_string(char s[], char rev[]);

int main()
{
    char s[stacksize], rev[stacksize];
    printf("Enter the string: ");
    scanf("%s", s);
    reverse_string(s, rev);
    printf("The reversed string is: %s\n", rev);
    return 0;
}

// reverse the string
void reverse_string(char s[], char rev[])
{
    int i, n, top = -1;
    char str[stacksize];
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        push(s[i], &top, str);
    }
    for (i = 0; i < n; i++)
    {
        rev[i] = pop(&top, str);
    }
    rev[i] = '\0';
}

// push to stack
void push(char item, int *top, char s[])
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

// pop from stack
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

// Output:
// Enter the string: hello
// The reversed string is: olleh
