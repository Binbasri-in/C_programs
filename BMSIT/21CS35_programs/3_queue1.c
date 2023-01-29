// 3.1 Implementing a queue using an array (ordinary queue)
// path: 21CS32_programs\3_queue1.c
#include <stdio.h>
#include <stdlib.h>

#define queue_size 5

// prototypes
void insert_rear(int item, int *rear, int q[]);
void delete_front(int *front, int *rear, int q[]);
void display(int front, int rear, int q[]);

int main()
{
    // the queue initialization
    int q[queue_size], front = 0, rear = -1, item, choice;
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
                    insert_rear(item, &rear, q);
                    break;
            case 2: delete_front(&front, &rear, q);
                    break;
            case 3: display(front, rear, q);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

// insert_rear function
void insert_rear(int item, int *rear, int q[])
{
    if(*rear == queue_size - 1)
        printf("Queue overflow\n");
    else
    {
        *rear = *rear + 1;
        q[*rear] = item;
    }
}

// delete_front function
void delete_front(int *front, int *rear, int q[])
{
    if(*front > *rear)
        printf("Queue is empty\n");
    else
    {
        printf("The deleted item is %d\n", q[*front]);
        *front = *front + 1;
    }
    if (*front > *rear)
    {
        *front = 0;
        *rear = -1;
    }
}

// display function
void display(int front, int rear, int q[])
{
    int i;
    if(front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("The contents of the queue are: ");
        for(i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

// Output:
// 1. Insert rear 2. Delete front 3. Display 4. Exit
// Enter your choice: 1
// Enter the item to be inserted: 10
// 1. Insert rear 2. Delete front 3. Display 4. Exit
// Enter your choice: 1
// Enter the item to be inserted: 20
// 1. Insert rear 2. Delete front 3. Display 4. Exit
// Enter your choice: 3
// The contents of the queue are: 10 20
// 1. Insert rear 2. Delete front 3. Display 4. Exit
// Enter your choice: 2
// The deleted item is 10
// 1. Insert rear 2. Delete front 3. Display 4. Exit
// Enter your choice: 3
// The contents of the queue are: 20