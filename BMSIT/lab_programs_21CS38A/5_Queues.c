#include <stdio.h>
#define queue_size 5

void insert_rear(int item, int *r, int q[])
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

void display(int f, int r, int q[])
{
    int i;

    // check underflow condition
    if(f > r)
    {
        printf("Queue is empty\n");
        return;
    }

    // display the queue
    printf("Contents of the queue are:\n");
    for(i = f; i <= r; i++)
        printf("%d\t",q[i]);
    printf("\n");
}

int main()
{
    // create queue, initialize front and rear
    int queue[queue_size];
    int front = 0, rear = -1;
    int choice, item;

    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d",&item);
                insert_rear(item, &rear, queue);
                break;
            case 2:
                delete_front(&front, &rear, queue);
                break;
            case 3:
                display(front, rear, queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}