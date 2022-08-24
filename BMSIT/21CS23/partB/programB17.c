/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B17- Design, develop and execute a C program with an appropriate structure definition 
and variable declaration to store information about an employee using nested 
structures. Consider the following fields like Ename, Empid, DOJ(Date, Month, 
Year) and Salary (Basic, DA, HRA)

input: The information of the employee
method: structures
output: The information of the employee
*/
#include <stdio.h>

struct employee
{
    char name[20];
    int empid;
    struct date
    {
        int day;
        int month;
        int year;
    } dob;
    struct salary
    {
        int basic;
        int da;
        int hra;
    } sal;
};

struct employee e;

int main()
{
    printf("Enter the name of the employee: ");
    scanf("%s", e.name);
    printf("Enter the empID of the employee: ");
    scanf("%d", &e.empid);
    printf("Enter the day of the employee's date of birth: ");
    scanf("%d", &e.dob.day);
    printf("Enter the month of the employee's date of birth: ");
    scanf("%d", &e.dob.month);
    printf("Enter the year of the employee's date of birth: ");
    scanf("%d", &e.dob.year);
    printf("Enter the basic salary of the employee: ");
    scanf("%d", &e.sal.basic);
    printf("Enter the DA of the employee: ");
    scanf("%d", &e.sal.da);
    printf("Enter the HRA of the employee: ");
    scanf("%d", &e.sal.hra);
    printf("The information of the employee is: \n");
    printf("Name: %s\n", e.name);
    printf("Empid: %d\n", e.empid);
    printf("Date of birth: %d/%d/%d\n", e.dob.day, e.dob.month, e.dob.year);
    printf("Salary: %d\n", e.sal.basic + e.sal.da + e.sal.hra);
}
