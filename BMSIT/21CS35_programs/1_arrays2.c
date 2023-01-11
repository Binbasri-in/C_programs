// 1.2 a program to find the sum of all elements of an array using pointers
// Path: 21CS32_programs\1_arrays2.c
#include<stdio.h>

int main()
{
    // initialize the array
    int arr[5]={1,2,3,4,5};
    // initialize the pointer to the array
    int *ptr=arr;
    // initialize the variable to store the sum
    int sum=0;
    // iterate through the array
    for(int i=0;i<5;i++)
    {
        // add the element to the sum
        sum+=*ptr;
        // increment the pointer
        ptr++;
    }
    // print the sum
    printf("Sum: %d",sum);
    return 0;
}