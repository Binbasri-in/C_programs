/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B16- Design, develop and execute a C program to implement structures to read, write 
and compute average- marks and the students scoring above and below the 
average marks for a class of N students

input: The number of students in the class and the marks of the students
method: structures
output: The average marks of the class, the number of students scoring above and below the average marks
*/
#include <stdio.h>

struct student
{
    int roll;
    int mark1, mark2, mark3;
    int avg;
};
struct student s[100];

int main()
{
    int n, i, sum = 0, avg = 0, above = 0, below = 0;
    printf("Enter the number of students in the class: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the roll number of the student: ");
        scanf("%d", &s[i].roll);
        printf("Enter the marks of the student: \n");
        scanf("%d %d %d", &s[i].mark1, &s[i].mark2, &s[i].mark3);
        s[i].avg = (s[i].mark1 + s[i].mark2 + s[i].mark3)/3;
    }
    for (i=0; i < n; i++)
    {
        sum += s[i].avg;
    }
    avg = sum/n;
    printf("The average marks of the class is: %d\n", avg);
    for (i = 0; i < n; i++)
    {
        if (s[i].avg > avg)
        {
            printf("student: %d, avg: %d, result: above average\n", s[i].roll, s[i].avg);
            above++;
        }
        else
        {
            printf("student: %d, avg: %d, result: below average\n", s[i].roll, s[i].avg);
            below++;
        }
    }
    
    printf("The number of students scoring above the average marks is: %d\n", above);
    printf("The number of students scoring below the average marks is: %d\n", below);
    return 0;
}