// 1.5 a program to perform binary search on an array using pointers
// Path: 21CS32_programs\1_arrays5.c
#include<stdio.h>

int main()
{
    // initialize the array
    int arr[]={2,3,4,5};
    // initialize the pointer to the array
    int *ptr=arr;
    // initialize the variable to store the item to be searched
    int item;
    // get the item to be searched
    printf("Enter the item to be searched: ");
    scanf("%d",&item);
    // initialize the variables to store the start and end of the array
    int start=0,end=4;
    // iterate through the array
    while(start<=end)
    {
        // initialize the variable to store the middle of the array
        int mid=(start+end)/2;
        // check if the element is equal to the item
        if(*(ptr+mid)==item)
        {
            // print the position
            printf("Position: %d",mid+1);
            return 0;
        }
        // check if the element is greater than the item
        else if(*(ptr+mid)>item)
        {
            // update the end
            end=mid-1;
        }
        // check if the element is less than the item
        else
        {
            // update the start
            start=mid+1;
        }
    }
    // print the message if the item is not found
    printf("Item not found");
    return 0;
}

// Output:
// Enter the item to be searched: 4
// Position: 3
