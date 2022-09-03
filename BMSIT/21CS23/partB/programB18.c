/*
Aothur: Mohammed Ali Al sakkaf
Date: 17/08/2022

question: B18- Design, develop and execute a C program to compute sin(x) using Taylor series 
approximation. Compare your result with the built-in library function. Print both 
the results with appropriate inferences. 

input: The value of x
method: Taylor series approximation
output: The value of sin(x)
*/
//question: B18- Design, develop and execute a C program to compute sin(x) using Taylor series 
//approximation. Compare your result with the built-in library function. Print both 
//the results with appropriate inferences. 
#include <stdio.h>
#include <math.h>
int fac(int n)
{
    int i,prod;
    prod=1;
    for (i=1;i<=n;i++)
    {
        prod*=i;
    }
    return prod;
}
float mysine(float x , int n)
{
    int i;
    float sum=0;
    for (i=0;i<=n;i++)
    {
        sum+=(pow(-1,i)*pow(x,2*i+1))/fac(2*i+1);
    }
    return sum;
}
void main()
{

    float x,n,rad,res;
    printf("Enter angle and terms\n");
    scanf("%f%f",&x,&n);
    rad=x*3.14/180;
    res=mysine(rad,n);
    printf("result using my function = %f \n",res);
    printf("result using built-in function = %f \n",sin(rad));
}