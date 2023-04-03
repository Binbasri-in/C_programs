// double ended queues
#include <stdio.h>
#define queue_size 50

void insert_front(int item, int *f, int *r, int q[])
{
    // check initial condition
    if(*f == 0 && *r != -1)
    {
        printf("Insert front is not possible\n");
        return;
    }
    if(*f == 0)
    {
        *r = *r + 1;
        q[*r] = item;
        return;
    }

    // insert the element
    *f = *f - 1;
    q[*f] = item;
}

void insert_rear(int item, int *f, int *r, int q[])
{
    // check overflow condition
    if(*r == queue_size - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    // insert the element
    *r = *r + 1;
    q[*r] = item;
}

void delete_front(int *f, int *r, int q[])
{
    int item;

    // check underflow condition
    if(*f > *r)
    {
        printf("Queue Underflow\n");
        return;
    }

    // delete the element
    printf("Item deleted is: %d\n",q[*f]);
    *f = *f + 1;

    // if reached end of queue, reset the queue
    if(*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void delete_rear(int *f, int *r, int q[])
{
    int item;

    // check underflow condition
    if(*f > *r)
    {
        printf("Queue Underflow\n");
        return;
    }

    // delete the element
    printf("Item deleted is: %d\n",q[*r]);
    *r = *r - 1;

    // if reached end of queue, reset the queue
    if(*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int *f, int *r, int q[])
{
    int i;

    // check underflow condition
    if(*f > *r)
    {
        printf("Queue Underflow\n");
        return;
    }

    // display the queue
    printf("Queue is: ");
    for(i = *f; i <= *r; i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}

void main()
{
    int f, r, q[queue_size], item, choice;

    // initialize the queue
    f = 0;
    r = -1;

    for(;;)
    {
        printf("1. Insert front\n");
        printf("2. Insert rear\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insert_front(item, &f, &r, q);
                    break;
            case 2: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insert_rear(item, &f, &r, q);
                    break;
            case 3: delete_front(&f, &r, q);
                    break;
            case 4: delete_rear(&f, &r, q);
                    break;
            case 5: display(&f, &r, q);
                    break;
            case 6: exit(0);
        }
    }
}


// output
// 1. Insert front
// 2. Insert rear
// 3. Delete front
// 4. Delete rear
// 5. Display
// 6. Exit
// Enter your choice: 1
// Enter the item to insert: 10
// 1. Insert front
// 2. Insert rear
// 3. Delete front
// 4. Delete rear
// 5. Display
// 6. Exit
// Enter your choice: 1
// Enter the item to insert: 20
// 1. Insert front
// 2. Insert rear
// 3. Delete front
// 4. Delete rear
// 5. Display
// 6. Exit
// Enter your choice: 5
// Queue is: 20 10
