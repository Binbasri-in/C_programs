//Implementing Merge Sort
#include <stdio.h>
// run with c99 only

//define size of array
#define SIZE 100

int array1[SIZE]; //array1 will be our input array
int array2[SIZE]; //array2 will be our secondary array

void merge(int low, int mid, int high) //sort elements of divided arrays and then merge them
{
    int i, j, k;

    for(i=low, j=mid+1, k=low; i<=mid && j<=high; k++) /*
 * "i" keeps track of first divided array, j keeps track of elements in second part of array, k will be for our secondary array*/
    {
        if(array1[i]<array1[j]) //pick out the lower element
        {
            array2[k]=array1[i++];
        }
        else    //pick out the lower element
        {
            array2[k] = array1[j++];
        }
    }
    while(i<=mid)   //if second part of array gets exhausted first
    {
        array2[k++]=array1[i++];
    }
    while(j<=high)  //if first part gets exhausted first
    {
        array2[k++]=array1[j++];
    }

    for (int l = 0; l <high+1 ; ++l)    //copy elements of array2 to array1
    {
        array1[l]=array2[l];
    }
}

void sort(int low, int high)
{
    if(low<high)    //check for number of elements!=1
    {
        int mid= (low + high)/2; //define mid element
        sort(low,mid); //call sort for half part of array
        sort(mid+1, high);// call sort for second half
        merge(low, mid, high);//merge both
    }
    else
        return; //return null when only one element is there
}

int main(void)
{
    int n;
    printf("\nEnter number of elements");
    scanf("%d", &n);
    printf("\nEnter %d elemnts", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &array1[i]);
    }
    printf("\nArray after sorting is : ");

    sort(0, n-1);

    for(int i=0; i<n; i++)
    {
        printf("%d ", array1[i]);
    }
}
