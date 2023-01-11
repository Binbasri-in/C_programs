// 3.2 Implementing a queue using arrays (circular queue)
// Path: 21CS32_programs\3_queue2.c
#include <stdio.h>
#include <stdlib.h>

#define queue_size 5

// prototypes
void insert_rear(int item, int *rear, int q[], int *count);
void delete_front(int *front, int *rear, int q[], int *count);
void display(int front, int rear, int q[], int count);

void main()
{
    // the queue initialization
    int q[queue_size], front = 0, rear = -1, item, choice, count = 0;
    // the menu
    for(;;)
    {
        printf("1. Insert rear\n2. Delete front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d", &item);
                    insert_rear(item, &rear, q, &count);
                    break;
            case 2: delete_front(&front, &rear, q, &count);
                    break;
            case 3: display(front, rear, q, count);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

// insert_rear function
void insert_rear(int item, int *rear, int q[], int *count)
{
    if(*count == queue_size)
        printf("Queue overflow\n");
    else
    {
        *rear = (*rear + 1) % queue_size;
        q[*rear] = item;
        *count = *count + 1;
    }
}

// delete_front function
void delete_front(int *front, int *rear, int q[], int *count)
{
    if(*count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("The deleted item is %d\n", q[*front]);
        *front = (*front + 1) % queue_size;
        *count = *count - 1;
    }
}

// display function
void display(int front, int rear, int q[], int count)
{
    int i;
    if(count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("The contents of the queue are: ");
        for(i = 1; i <= count; i++)
        {
            printf("%d ", q[front]);
            front = (front + 1) % queue_size;
        }
        printf("\n");
    }
}