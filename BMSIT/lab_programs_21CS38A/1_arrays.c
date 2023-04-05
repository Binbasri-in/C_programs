// 1.Design, Develop and Implement a menu driven Program in C for the following
// Array operations
// a. Creating an Array of N Integer Elements
// b. Display of Array Elements with Suitable Headings
// c. Inserting an Element (ELEM) at a given valid Position (POS)
// d. Deleting an Element at a given valid Position(POS)
// e. Exit.
// Support the program with functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>

int *a;        // Pointer to hold the memory alocated for array
int arraysize; // Maximum number of elements that the array can hold
int n = 0;     // number of elements in the array at any given instant

void create_array()
{
    int i;
    a = (int *)malloc(arraysize * sizeof(int));
    if (a == NULL)
    {
        printf("Array creation failed\n");
        exit(0);
    }
    printf("Array created\n");
    printf("Enter %d elements\n", n); // n is the current no of elements
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display_array()
{
    int i;
    if(n == 0)
    {
        printf("No elements in the array\n");
        return;
    }
    printf("The array elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insert_array(int item, int pos)
{
    int i;
    if (n == arraysize)
    {
        printf("Array is full. Cannot insert \n");
        return;
    }
    if (pos > n || pos < 0)
    {
        printf("Invalid position \n");
        return;
    }
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = item;
    n = n + 1;
}

void delete_array(int pos)
{
    int i;
    if (n == 0)
    {
        printf("No elements in the array, Cannot delete\n");
        return;
    }
    if (pos >= n || pos < 0)
    {
        printf("Invalid position \n");
        return;
    }
    printf("Item deleted= %d \n", a[pos]);
    for (i = pos + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n = n - 1;
}

int main()
{
    int item, pos, choice;
    printf("To Create an Array\n");
    printf("Enter the maximum size of array\n");
    scanf("%d", &arraysize);
    printf("Enter the number of elements to be read initially \n");
    scanf("%d", &n);
    create_array();
    for (;;)
    {
        printf("l.Display 2.Insert 3.Delete 4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_array();
            break;
        case 2:
            printf("Enter the item to insert\n");
            scanf("%d", &item);
            printf("Enter the index position to insert\n");
            scanf("%d", &pos);
            insert_array(item, pos);
            break;
        case 3:
            printf("Enter the index position to delete\n");
            scanf("%d", &pos);
            delete_array(pos);
            break;
        case 4:
            free(a);
            exit(0);
        }
    }
}
