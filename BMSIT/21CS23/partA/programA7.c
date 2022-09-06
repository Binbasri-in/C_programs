/*
Aothur: Mohammed Ali Al sakkaf
Date: 14/08/2022

question: A7- develop a c program to find the revers of a positive number and check if it is a palindrom

input: a positive number
method: take number by number and revers
output: the reversed number and is it a palindom or not
*/
#include <stdio.h>

int main(void)
{
    // get the number from the user
    int n;
    printf("Enter the number: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
    	printf("Invalid Input\n");
    	return 1;
    }
    // find the reverse of the number
    int reverse = 0;
    int temp = n;
    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp = temp / 10;
    }
    
    // print the reverse of the number
    printf("The reverse of the number is: %d\n", reverse);

    // check if it is a palindrome
    if (reverse == n)
        printf("%d is a palindrome\n", n);
    else
        printf("%d is not a palindrome\n", n);

    return 0;
}
