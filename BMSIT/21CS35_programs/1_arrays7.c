// 1.7 a program to merge two sorted array elements into a single sorted array
// Path: 21CS32_programs\1_arrays7.c
#include<stdio.h>

int main()
{
    // initialize the index variables
    int n1, n2, i, j, k;
    // get the number of elements in the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    // initialize the first array
    int arr1[n1];
    // get the elements of the first array
    printf("Enter the elements of the first array: ");
    for(i=0; i<n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    // get the number of elements in the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    // initialize the second array
    int arr2[n2];
    // get the elements of the second array
    printf("Enter the elements of the second array: ");
    for(i=0; i<n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // initialize the index variables
    i=0;
    j=0;
    k=0;
    // initialize the merged array
    int arr3[n1+n2];
    // iterate through the arrays
    while(i<n1 && j<n2)
    {
        // check if the element of the first array is less than the element of the second array
        if(arr1[i]<arr2[j])
        {
            // add the element of the first array to the merged array
            arr3[k]=arr1[i];
            // increment the index variables
            i++;
            k++;
        }
        // check if the element of the second array is less than the element of the first array
        else if(arr2[j]<arr1[i])
        {
            // add the element of the second array to the merged array
            arr3[k]=arr2[j];
            // increment the index variables
            j++;
            k++;
        }
        // check if the element of the first array is equal to the element of the second array
        else
        {
            // add the element of the first array to the merged array
            arr3[k]=arr1[i];
            // increment the index variables
            i++;
            k++;
            // add the element of the second array to the merged array
            arr3[k]=arr2[j];
            // increment the index variables
            j++;
            k++;
        }
    }
    // check if the elements of the first array are left
    while(i<n1)
    {
        // add the element of the first array to the merged array
        arr3[k]=arr1[i];
        // increment the index variables
        i++;
        k++;
    }
    // check if the elements of the second array are left
    while(j<n2)
    {
        // add the element of the second array to the merged array
        arr3[k]=arr2[j];
        // increment the index variables
        j++;
        k++;
    }
    // print the merged array
    printf("The merged array is: ");
    for(i=0; i<n1+n2; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    return 0;
}

// Output:
// Enter the number of elements in the first array: 5
// Enter the elements of the first array: 1 3 5 7 9
// Enter the number of elements in the second array: 5
// Enter the elements of the second array: 2 4 6 8 10
// The merged array is: 1 2 3 4 5 6 7 8 9 10
