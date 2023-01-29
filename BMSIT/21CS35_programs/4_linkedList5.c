// 4.5 demonstration of reverse function of linked list
// Path: 21CS35_programs\4_linkedList5.c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

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
    // reverse the list
    NODE rev = reverse(first);
    // print the reversed list
    NODE cur = rev;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}

// Output:
// 40 30 20 10