// double ended queues

// 6. de-queue

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// global
int q[MAX];
int r = -1, f = 0;

// prototypes
void insert_rear(int item);
void insert_front(int item);
void delete_front();
void delete_rear();
void display();

void main()
{
    int item, choice;

    for(;;)
    {
        printf("1. Insert front  2. Insert rear  3. Delete front  4. Delete rear  5. Display  6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insert_front(item);
                    break;
            case 2: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insert_rear(item);
                    break;
            case 3: delete_front();
                    break;
            case 4: delete_rear();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
        }
    }
}

void insert_rear(int item)
{
    if(r == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    q[++r] = item;
}

void insert_front(int item)
{
    if(f == 0 && r != -1)
    {
        printf("Queue overflow front\n");
        return;
    }
    if(f == 0)
    {
        q[++r] = item;
        return;
    }
    q[--f] = item;
}

void delete_front()
{
    if(f > r)
    {
        printf("Queue underflow\n");
        return;
    }
    f++;
}

void delete_rear()
{
    if(f > r)
    {
        printf("Queue underflow\n");
        return;
    }
    r--;
}

void display()
{
    int i;

    if(f > r)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: ");
    for(i = f; i <= r; i++)
        printf("%d ",q[i]);
    printf("\n");
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
