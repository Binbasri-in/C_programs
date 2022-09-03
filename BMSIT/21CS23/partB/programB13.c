/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022
question: B13- Design, develop and execute a C program with / without using functions to sort ‘n’ 
elements of an array using bubble sort technique.

input: The array to be sorted
method: bubble sort
output: The array sorted in ascending order
*/
#include <stdio.h>

int bubbleSort(int arr[], int n);

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
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }
    }
    bubbleSort(a, n);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}