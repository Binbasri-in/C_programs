// 3.4 implementation of double ended queue
// Path: 21CS32_programs\3_queue4.c
#include <stdio.h>
#include <stdlib.h>

#define queue_size 5
int queue[queue_size];

// prototypes
void insert_rear(int item, int *rear, int *count);
void insert_front(int item, int *front, int *count);
void delete_front(int *front, int *rear, int *count);
void delete_rear(int *front, int *rear, int *count);
void display(int front, int rear, int *q, int count);

// main function
int main()
{
    // the queue initialization
    
    int front = 0, rear = -1, item, choice, count = 0;
    // the menu
    for (;;)
    {
        printf("1. Insert rear\n2. Insert front\n3. Delete front\n4. Delete rear\n5. Display\n6. Exit\n");
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
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_front(item, &front, &count);
            break;
        case 3:
            delete_front(&front, &rear, &count);
            break;
        case 4:
            delete_rear(&front, &rear, &count);
            break;
        case 5:
            display(front, rear, queue, count);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

// insert at rear
void insert_rear(int item, int *rear, int *count)
{
    if (*count == queue_size)
    {
        printf("Queue overflow\n");
        return;
    }
    *rear = (*rear + 1) % queue_size;
    queue[*rear] = item;
    *count = *count + 1;
}

// insert at front
void insert_front(int item, int *front, int *count)
{
    if (*count == queue_size)
    {
        printf("Queue overflow\n");
        return;
    }
    *front = (*front - 1 + queue_size) % queue_size;
    queue[*front] = item;
    *count = *count + 1;
}

// delete from front
void delete_front(int *front, int *rear, int *count)
{
    if (*count == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("The deleted item is %d\n", queue[*front]);
    *front = (*front + 1) % queue_size;
    *count = *count - 1;
}

// delete from rear
void delete_rear(int *front, int *rear, int *count)
{
    if (*count == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("The deleted item is %d\n", queue[*rear]);
    *rear = (*rear - 1 + queue_size) % queue_size;
    *count = *count - 1;
}

// display
void display(int front, int rear, int *q, int count)
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The queue is: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", q[front]);
        front = (front + 1) % queue_size;
    }
    printf("\n");
}

// Output:
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 1
//Enter the item to be inserted: 10
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 1
//Enter the item to be inserted: 20
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 2
//Enter the item to be inserted: 30
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 5
//The queue is: 30 10 20
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 3
//The deleted item is 30
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 4
//The deleted item is 20
//1. Insert rear 2. Insert front 3. Delete front  4. Delete rear 5. Display  6. Exit
//Enter your choice: 5
//The queue is: 10