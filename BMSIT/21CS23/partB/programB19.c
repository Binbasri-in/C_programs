/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B19- Develop a C program using pointers to compute the sum, mean and standard 
deviation of all elements stored in an array of N real numbers

input: The number of elements in the array and the elements of the array
method: pointers
output: The sum, mean and standard deviation of the array
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float sum = 0, mean = 0, sd = 0, *p;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    p = arr;
    printf("Enter the element of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", p + i);
        sum += *(p + i);
    }
    mean = sum / n;
    for (i = 0; i < n; i++)
    {
        sd += (*(p + i) - mean) * (*(p + i) - mean);
    }
    sd = sd / n;
    sd = sqrt(sd);
    printf("The sum of the array is: %f\n", sum);
    printf("The mean of the array is: %f\n", mean);
    printf("The standard deviation of the array is: %f\n", sd);
    free(p);
    return 0;
}
