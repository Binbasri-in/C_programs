/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B20- Design, develop and execute a C program using functions to implement string 
operations such as compare, concatenate, string length. Convince the parameter 
passing techniques. Do not use in-built string functions

input: The two strings to be compared
method: string operations
output: The result of the comparison
*/
#include <stdio.h>

int compare(char *str1, char *str2);
int concatenate(char *str1, char *str2);
int stringLength(char *str);

int main(void)
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("The result of the comparison is: %d\n", compare(str1, str2));
    printf("The result of the concatenation is: %d\n", concatenate(str1, str2));
    printf("The length of the string is: %d\n", stringLength(str1));
}

int compare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int concatenate(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    return 1;
}

int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

