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

// global
int *a = NULL;
int max_size = 100;
int n = 0;

// prototypes
void create_array();
void display_array();
void insert_to(int item, int pos);
void delete_from(int pos);

void main()
{
    int ch, item, pos;

    printf("Enter number of items to insert initially: ");
    scanf("%d", &n);

    create_array();

    for(;;)
    {
        printf("1.display  2.insert  3.delete  4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: display_array();
                    break;
            case 2: printf("Enter item to insert: ");
                    scanf("%d", &item);
                    printf("Enter position(start from 0): ");
                    scanf("%d", &pos);
                    insert_to(item, pos);
                    break;
            case 3: printf("Enter position to delete(start from 0): ");
                    scanf("%d", &pos);
                    delete_from(pos);
                    break;
            case 4: exit(0);
                    break;
        }
    }
}

void create_array()
{
    int i;

    a = malloc(max_size*sizeof(int)); // allocate memory for the array

    printf("Enter %d Element to insert to array\n", n); // insert n elements to the array
    for(i = 0; i < n; i++)
        scanf("%d", (a+i));

}


void display_array()
{
    int i;

    printf("The array is: "); // print out each elemnt from the array
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    
    printf("\n");
}

void insert_to(int item, int pos)
{
    int i;

    if (pos > n || pos < 0) // check the position
    {
        printf("Invalid position\n");
        return;
    }

    // free space at the position by moving each one after it one step to the right
    for (i = n - 1; i >= pos; i--)
        a[i+1] = a[i];

    a[pos] = item; // insert the item into the position
    n = n + 1; // increment the elements counter
}


void delete_from(int pos)
{
    int i;

    if (pos > n || pos < 0) // check the position
    {
        printf("Invalid position\n");
        return;
    }

    printf("item deleted is: %d\n", a[pos]);// print item deleted

    // move each element one step to the left to delete the item
    for (i = pos + 1; i < n; i++)
        a[i-1] = a[i];

    n = n - 1; // decrement the elements counter
}
