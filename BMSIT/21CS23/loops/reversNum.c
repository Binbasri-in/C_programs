#include <stdio.h>

int main(void)
{
    // get the number from the user
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
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
    {
        printf("%d is a palindrome\n", n);
    }
    else
    {
        printf("%d is not a palindrome\n", n);
    }

    return 0;
}