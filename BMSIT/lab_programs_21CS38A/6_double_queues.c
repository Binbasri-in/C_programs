// double ended queues
#include <stdio.h>
#define queue_size 5

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