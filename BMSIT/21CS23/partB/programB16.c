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
    int marks;
};
struct student s[100];

int main()
{
    int n, i, j, sum = 0, avg = 0, above = 0, below = 0;
    printf("Enter the number of students in the class: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the roll number of the student: ");
        scanf("%d", &s[i].roll);
        printf("Enter the marks of the student: ");
        scanf("%d", &s[i].marks);
        sum += s[i].marks;
    }
    avg = sum / n;
    for (i = 0; i < n; i++)
    {
        if (s[i].marks > avg)
        {
            above++;
        }
        else
        {
            below++;
        }
    }
    printf("The average marks of the class is: %d\n", avg);
    printf("The number of students scoring above the average marks is: %d\n", above);
    printf("The number of students scoring below the average marks is: %d\n", below);
}