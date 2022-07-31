#include <stdio.h>

int main(void)
{
    int marks;
    printf("Enter marks: ");
    if (scanf("%d", &marks) != 1 || marks < 0 || marks > 100)
    {
        printf("Invalid marks.\n");
        return 1;
    }
    if (marks >= 90)
        printf("Grade: O\n");
    else if (marks >= 80)
        printf("Grade: A\n");
    else if (marks >= 70)
        printf("Grade: B\n");
    else if (marks >= 60)
        printf("Grade: C\n");
    else if (marks >= 50)
        printf("Grade: D\n");
    else if (marks >= 40)
        printf("Grade: E\n");
    else
        printf("Grade: F\n");

    return 0;
}