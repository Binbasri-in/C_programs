#include <stdio.h>
#define queue_size 5

void insert_front(int item);

void main()
{
    int queue[queue_size];
    int front = 0, rear = -1;
    int item, choice;

    while(1)
    {
        printf("1. Insert front 2. Insert rear 3. Delete front 4. Delete rear 5.display 6.Exit\n");
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
                    queue[++rear] = item;
                    break;
            case 3: front++;
                    break;
            case 4: rear--;
                    break;
            case 5: for(int i = front; i <= rear; i++)
                        printf("%d ", queue[i]);
                    printf("\n");
                    break;
            case 6: exit(0);
        }
    }
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