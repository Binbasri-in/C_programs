/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B14- Design, develop and execute a C program with / without using functions to sort ‘n’ 
elements of an array using selection sort technique.

input: The array to be sorted
method: selection sort
output: The array sorted in ascending order
*/
#include <stdio.h>

int selectionSort(int arr[], int n);

int main(void)
{
    int n, i;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }
    int a[n];
    printf("Enter the elements of the array\n ");
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &n) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }
    }
    selectionSort(a, n);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int selectionSort(int arr[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}