// 5. circular queues

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// global
int q[MAX];
int r = -1, f = 0, count = 0;

//prototypes
void insert_rear(int item);
void delete_front();
void under_or_over_flow();
void display();

void main()
{
    int ch, item;

    for(;;)
    {
        printf("1.insert rear  2.delete front  3.check status  4.display  5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter item to insert: ");
                    scanf("%d", &item);
                    insert_rear(item);
                    break;
            case 2: delete_front();
                    break;
            case 3: under_or_over_flow();
                    break;
            case 4: display();
                    break;
            default: exit(0);
        }
    }
}

void insert_rear(int item)
{
    if (count == MAX-1)
    {
        printf("Queue is overflow\n");
        return;
    }

    r = (r+1) % MAX;
    q[r] = item;
    count = count + 1;
}


void delete_front()
{
    if (count == 0)
    {
        printf("Queue is underflow\n");
        return;
    }

    printf("Deleted: %d\n", q[f]);
    f = (f + 1) % MAX;
    count = count - 1;
}

void under_or_over_flow()
{
    if (count == MAX-1)
        printf("Queue is overflow\n");
    else if (count == 0)
        printf("Queue is underflow\n");
    else
        printf("Not underflow nor overflow\n");
}

void display()
{
    int i;
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("The Queue is: ");
    for (i = 0; i < count; i++)
        printf("%d\t", q[(f+i)%MAX]);
    printf("\n");
}
