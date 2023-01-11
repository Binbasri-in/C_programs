// 1.6 a program to perform bubble sort on an array using pointers
// Path: 21CS32_programs\1_arrays6.c
#include<stdio.h>

int main()
{
    // initialize the array
    int arr[5]={5,4,3,2,1};
    // initialize the pointer to the array
    int *ptr=arr;
    // initialize the variable to store the number of passes
    int passes=0;
    // iterate through the array
    for(int i=0;i<5;i++)
    {
        // iterate through the array
        for(int j=0;j<5;j++)
        {
            // check if the element is greater than the next element
            if(*ptr>*(ptr+1))
            {
                // swap the elements
                int temp=*ptr;
                *ptr=*(ptr+1);
                *(ptr+1)=temp;
            }
            // increment the pointer
            ptr++;
        }
        // increment the pointer
        ptr=arr;
        // increment the number of passes
        passes++;
    }
    // initialize the pointer to the array
    ptr=arr;
    // iterate through the array
    for(int i=0;i<5;i++)
    {
        // print the element
        printf("%d\t",*ptr);
        // increment the pointer
        ptr++;
    }
    return 0;
}
