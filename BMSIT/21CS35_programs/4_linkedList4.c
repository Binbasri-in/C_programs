// 4.4 demonstration of concatination of two linked lists
// Path: 21CS35_programs\4_linkedList4.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;


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

    // create another list
    NODE first2 = (NODE)malloc(sizeof(struct node));
    NODE second2 = (NODE)malloc(sizeof(struct node));
    NODE third2 = (NODE)malloc(sizeof(struct node));
    NODE fourth2 = (NODE)malloc(sizeof(struct node));
    first2->data = 50;
    first2->next = second2;
    second2->data = 60;
    second2->next = third2;
    third2->data = 70;
    third2->next = fourth2;
    fourth2->data = 80;
    fourth2->next = NULL;

    // concatenate the two lists
    NODE newFirst = concat(first, first2);
    // display the new list
    NODE cur = newFirst;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}

// Output:
// 10 20 30 40 50 60 70 80
