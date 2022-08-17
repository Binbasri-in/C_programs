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

int binarySearch(int a[], int n, int key);

int main(void)
{
    int n, key, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the key element: ");
    scanf("%d", &key);
    pos = binarySearch(a, n, key);

    if (pos == -1)
    {
        printf("The key element is not found in the array.\n");
    }
    else
    {
        printf("The key element is found in the array at position %d.\n", pos);
    }
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid+1;
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
    return -1;
}