// 3.5 Implementing periority queues using arrays
// Path: 21CS32_programs\3_queue5.c
#include <stdio.h>
#include <stdlib.h>

#define queue_size 5

// prototypes
void insert_order(int item, int *rear, int *rear, int q[]);
void delete_front(int *front, int *rear, int q[]);
void display(int front, int rear, int q[]);

// main function
void main()
{
    // the queue initialization
    int queue[queue_size];
    int front = 0, rear = -1, item, choice;
    // the menu
    for (;;)
    {
        printf("1. Insert\n2. Delete front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_order(item, &front, &rear, queue);
            break;
        case 2:
            delete_front(&front, &rear, queue);
            break;
        case 3:
            display(front, rear, queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

// insert_order function
void insert_order(int item, int *front, int *rear, int q[])
{
    int j;
    if (*rear == queue_size - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    j = *rear;
    while (j >= *front && item < q[j])
    {
        q[j + 1] = q[j];
        j--;
    }
    q[j + 1] = item;
    *rear = *rear + 1;
}

// delete_front function
void delete_front(int *front, int *rear, int q[])
{
    if (*front > *rear)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("Item deleted = %d\n", q[*front]);
    *front = *front + 1;
}

// display function
void display(int front, int rear, int q[])
{
    int i;
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is :\n");
    for (i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}