/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B12- Design, develop and execute a C program with / without using functions to search 
for a given key element in an array of ‘n’ elements using binary search technique

input: The sorted array and the key element
method: binary search
output: The position of the key element in the array
*/
#include <stdio.h>

void binarySearch(int a[], int n, int key);

int main(void)
{
    int n, key, pos;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input\n");
        return 1;
    }
    int a[n];
    printf("Enter the elements of the array\n ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("Enter the key element: ");
    if (scanf("%d", &key) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }

    binarySearch(a, n, key);


    return 0;
}

void binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            printf("%d is in the array at position %d.\n", key, mid+1);
            return
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%d is not found in the array.\n", key);
}