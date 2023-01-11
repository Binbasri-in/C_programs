// 3.3 Implementing a circular queue using dynamic arrays (double capacity queue)
// Path: 21CS32_programs\3_queue3.c
#include <stdio.h>
#include <stdlib.h>

int capacity = 5;
int *queue;

// prototypes
void insert_rear(int item, int *rear, int *count);
void delete_front(int *front, int *rear, int *count);
void display(int front, int rear, int *q, int count);

// main function
void main()
{
    // the queue initialization
    queue = (int *)malloc(capacity * sizeof(int));
    int front = 0, rear = -1, item, choice, count = 0;
    // the menu
    for (;;)
    {
        printf("1. Insert rear\n2. Delete front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_rear(item, &rear, &count);
            break;
        case 2:
            delete_front(&front, &rear, &count);
            break;
        case 3:
            display(front, rear, queue, count);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

// insert_rear function
void insert_rear(int item, int *rear, int *count)
{
    if (*count == capacity)
    {
        printf("Queue overflow\n");
        capacity = capacity * 2;
        queue = (int *)realloc(queue, capacity * sizeof(int));
    }
    else
    {
        *rear = (*rear + 1) % capacity;
        queue[*rear] = item;
        *count = *count + 1;
    }
}

// delete_front function
void delete_front(int *front, int *rear, int *count)
{
    if (*count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("The deleted item is %d\n", queue[*front]);
        *front = (*front + 1) % capacity;
        *count = *count - 1;
    }
}

// display function
void display(int front, int rear, int *q, int count)
{
    if (count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("The queue is: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}