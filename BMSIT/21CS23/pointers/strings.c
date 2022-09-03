// program for reading and printing name of student
#include <stdio.h>

void main()
{
    char name[20];
    printf("Enter name of student: ");
    scanf("%[^\n]", name);
    printf("The Entered name is %s", name);
}