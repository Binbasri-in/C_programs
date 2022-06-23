#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check if CLI input or normal
    if (argc == 1)
    {
        // if name not entered with CLI ask for name and output
        char name[30];
        printf("Enter your first name: ");
        scanf("%s", name);
        printf("***Hello, %s To my 100 programs, hope you enjoy it***\n", name);
    }
    else
    {
        // if name is given by CLI output the statment
        printf("***Hello, %s To my 100 programs, hope you enjoy it***\n", argv[1]);
    }
}