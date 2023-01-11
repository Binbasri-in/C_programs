// 1.4 a program to perform linear search on an array using pointers
// Path: 21CS32_programs\1_arrays4.c
#include<stdio.h>

int main()
{
    // initialize the array
    int arr[5]={1,2,3,4,5};
    // initialize the pointer to the array
    int *ptr=arr;
    // initialize the variable to store the item to be searched
    int item;
    // get the item to be searched
    printf("Enter the item to be searched: ");
    scanf("%d",&item);
    // iterate through the array
    for(int i=0;i<5;i++)
    {
        // check if the element is equal to the item
        if(*ptr==item)
        {
            // print the position
            printf("Position: %d",i);
            return 0;
        }
        // increment the pointer
        ptr++;
    }
    // print the message if the item is not found
    printf("Item not found");
    return 0;
}