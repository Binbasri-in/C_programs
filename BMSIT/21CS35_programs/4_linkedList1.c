// 4.1 Implementing Singly Linked List
// Path: 21CS32_programs\4_linkedList1.c

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

// function to create 2 nodes list
NODE create2()
{
    NODE first = (NODE)malloc(sizeof(struct node));
    NODE second = (NODE)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = NULL;
    return first;
}

// function to insert an element at the front end
NODE insert_front(NODE first, int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = first;
    first = temp;
    return first;
}
 
// function to insert an element at the rear end
NODE insert_rear(NODE first, int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    if (first == NULL)
        return temp;
    NODE cur = first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return first;
}

// function to delete node at the front end
NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
    return first;
}

// function to delete node at the rear end
NODE delete_rear(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (first->next == NULL)
    {
        printf("Deleted element is %d\n", first->data);
        free(first);
        return NULL;
    }
    NODE cur = first;
    while (cur->next->next != NULL)
        cur = cur->next;
    printf("Deleted element is %d\n", cur->next->data);
    free(cur->next);
    cur->next = NULL;
    return first;
}

// function to display the list
void display(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = first;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// main function for all the operations
int main()
{
    NODE first = NULL;
    int choice, item;
    for (;;)
    {
        printf("1:Create 2:Insert_front 3:Insert_rear 4:Delete_front 5:Delete_rear 6:Display 7:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = create2();
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_front(first, item);
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_rear(first, item);
            break;
        case 4:
            first = delete_front(first);
            break;
        case 5:
            first = delete_rear(first);
            break;
        case 6:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}
