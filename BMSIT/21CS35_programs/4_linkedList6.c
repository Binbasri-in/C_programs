// 4.6 demonstration of delete where data is given or its position is given
// Path: 21CS35_programs\4_linkedList6.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

// function to delete a node whose data is given
NODE delete_node(NODE first, int item)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (first->data == item)
    {
        NODE temp = first;
        first = first->next;
        free(temp);
        return first;
    }
    NODE prev = first;
    NODE cur = first->next;
    while (cur != NULL)
    {
        if (cur->data == item)
        {
            prev->next = cur->next;
            printf("Item deleted: %d\n", item)
            free(cur);
            return first;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Item not found\n");
    return first;
}

// function to insert an item at a given position
NODE insert_pos(NODE first, int item, int pos)
{
    if (pos == 1)
    {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = first;
        first = temp;
        return first;
    }
    NODE prev = first;
    NODE cur = first->next;
    int i = 2;
    while (cur != NULL)
    {
        if (i == pos)
        {
            NODE temp = (NODE)malloc(sizeof(struct node));
            temp->data = item;
            temp->next = cur;
            prev->next = temp;
            return first;
        }
        prev = cur;
        cur = cur->next;
        i++;
    }
    printf("Invalid position\n");
    return first;
}

int main()
{
    // create a linked list with 3 nodes
    NODE first = (NODE)malloc(sizeof(struct node));
    NODE second = (NODE)malloc(sizeof(struct node));
    NODE third = (NODE)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    // delete a node whose data is given
    first = delete_node(first, 20);
    // print the list
    NODE cur = first;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    // insert an item at a given position
    first = insert_pos(first, 40, 2);
    // print the list
    cur = first;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}

// Output:
// Item deleted: 20
// 10 30
// 10 40 30
