// circular queues
#include <stdio.h>
#define queue_size 5

void insert_rear(int item, int *r,int *count, int q[])
{
    // check overflow condition
    if(*count == queue_size)
    {
        printf("Queue Overflow\n");
        return;
    }

    // insert the element
    *r = (*r + 1) % queue_size;
    q[*r] = item;
    *count = *count + 1;
}

void delete_front(int *f, int *count, int q[])
{
    int item;

    // check underflow condition
    if(*count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    // delete the element
    printf("Item deleted is: %d\n",q[*f]);
    *f = (*f + 1) % queue_size;
    *count = *count - 1;
}

void display(int f, int r, int count, int q[])
{
    int i;

    // check underflow condition
    if(count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    // display the queue
    printf("Contents of the queue are:\n");
    for(i = 0; i < count; i++)
        printf("%d\t",q[(f + i) % queue_size]);
    printf("\n");
}

int main()
{
    int queue[queue_size], front = 0, rear = -1, count = 0, choice, item;

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
                insert_rear(item, &rear, &count, queue);
                break;
            case 2:
                delete_front(&front, &count, queue);
                break;
            case 3:
                display(front, rear, count, queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}