// 1.3 a program to read and print an array of m * n matrix using pointers
// Path: 21CS32_programs\1_arrays3.c
#include<stdio.h>

int main()
{
    // initialize the variables to store the number of rows and columns
    int m,n;
    // get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    // initialize the array
    int arr[m][n];
    // initialize the pointer to the array
    int *ptr=arr;
    // iterate through the array
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // get the element
            printf("Enter the element at position (%d,%d): ",i,j);
            scanf("%d",ptr);
            // increment the pointer
            ptr++;
        }
    }
    // initialize the pointer to the array
    ptr=arr;
    // iterate through the array
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // print the element
            printf("%d\t",*ptr);
            // increment the pointer
            ptr++;
        }
        printf("\n");
    }
    return 0;
}