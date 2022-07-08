#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[100];
    gets(name);
    printf("Hello, %s!\n", name);
}