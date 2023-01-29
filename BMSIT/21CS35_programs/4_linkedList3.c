// 4.3 demonstration of count function of linked list
// Path: 21CS35_programs\4_linkedList3.c
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

int main()
{
    // create a list
    NODE first = (NODE)malloc(sizeof(struct node));
    NODE second = (NODE)malloc(sizeof(struct node));
    NODE third = (NODE)malloc(sizeof(struct node));
    NODE fourth = (NODE)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = NULL;
    // count the number of nodes in the list
    int c = count(first);
    printf("Number of nodes in the list: %d\n", c);
    return 0;
}

// Output:
// Number of nodes in the list: 4
