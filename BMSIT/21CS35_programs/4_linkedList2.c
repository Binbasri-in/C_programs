// 4.2 More operational functions for linked lists (write your own main function)
// path: 21CS35_programs\4_linkedList2.c

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

// function to count the number of nodes in the list
int count(NODE first)
{
    int c = 0;
    NODE cur = first;
    while (cur != NULL)
    {
        c++;
        cur = cur->next;
    }
    return c;
}

// function to concatenate two lists
NODE concat(NODE first, NODE second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    NODE cur = first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = second;
    return first;
}

// function to reverse a SLL without creating a new list
NODE reverse(NODE first)
{
    if (first == NULL)
        return NULL;
    NODE temp = NULL;
    NODE cur;
    while (first != NULL)
    {
        cur = first;
        first = first->next;
        cur->next = temp;
        temp = cur;
    }
    return temp;
}

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

// function to insert