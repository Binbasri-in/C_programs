// 1.1 a program to print the elements of an array along with their address using pointers
// Path: 21CS32_programs\1_arrays1.c
#include<stdio.h>

int main()
{
    // initialize the array
    int arr[5]={1,2,3,4,5};
    // initialize the pointer to the array
    int *ptr=arr;
    // iterate through the array
    for(int i=0;i<5;i++)
    {
        // print the element and its address
        printf("Element: %d\tAddress: %p\n",*ptr,ptr);
        // increment the pointer
        ptr++;
    }
    return 0;
}