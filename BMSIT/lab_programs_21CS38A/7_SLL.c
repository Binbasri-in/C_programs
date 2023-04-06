// 7.SLL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char usn[10];
    char name[20];
    char branch[20];
    int sem;
    char phno[20];
    struct node *next;
};

typedef struct node* NODE;

// prototypes
NODE read_node();
void print_node(NODE);
NODE insert_front(NODE);
NODE insert_rear(NODE);
NODE delete_front(NODE);
NODE delete_rear(NODE);
void display(NODE);

// main function
int main()
{
    int choice, n, i;
    NODE first = NULL;

    // Create a list of 'n' students using front insertion
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        first = insert_rear(first);
    }
    for(;;)
    {
        printf("1. Insert front  2. Insert rear  3. Delete front  4. Delete rear  5. Display  6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: first = insert_front(first);
                    break;
            case 2: first = insert_rear(first);
                    break;
            case 3: first = delete_front(first);
                    break;
            case 4: first = delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            default: exit(0);
        }
    }
}

// read a node
NODE read_node()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the USN: ");
    scanf("%s", temp->usn);
    printf("Enter the name: ");
    scanf("%s", temp->name);
    printf("Enter the branch: ");
    scanf("%s", temp->branch);
    printf("Enter the semester: ");
    scanf("%d", &temp->sem);
    printf("Enter the phone number: ");
    scanf("%s", temp->phno);
    temp->next = NULL;
    return temp;
}

// print a node
void print_node(NODE temp)
{
    printf("USN: %s\n", temp->usn);
    printf("Name: %s\n", temp->name);
    printf("Branch: %s\n", temp->branch);
    printf("Semester: %d\n", temp->sem);
    printf("Phone number: %s\n", temp->phno);
}

// insert a node at the front
NODE insert_front(NODE first)
{
    NODE temp;
    temp = read_node(); // create the node

    temp->next = first; // insert the node at the front
    return temp;
}

// insert a node at the rear
NODE insert_rear(NODE first)
{
    NODE temp, cur;
    temp = read_node(); // create the node

    if (first == NULL) // if the list is empty return temp directly
        return temp;

    cur = first;  // else traverse to the end of the list and insert it
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;

    return first; // return the first node
}

// delete a node from the front
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL) //if the list is empty
    {
        printf("List is empty\n");
        return NULL;
    }
    temp = first; // else delete the first node
    first = first->next;
    printf("The deleted node is:\n");
    print_node(temp);
    free(temp);

    return first; // return the first node
}

// delete a node from the rear
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL) // if the list is empty
    {
        printf("List is empty\n");
        return NULL;
    }
    if (first->next == NULL) // if the list has only one node
    {
        printf("The deleted node is:\n");
        print_node(first);
        free(first);
        return NULL;
    }
    // else traverse to the end of the list and delete the last node
    prev = NULL;
    cur = first;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    printf("The deleted node is:\n");
    print_node(cur);
    free(cur);
    prev->next = NULL;

    return first; // return the first node
}

// display the list
void display(NODE first)
{
    NODE cur;
    if (first == NULL) // if the list is empty
    {
        printf("List is empty\n");
        return;
    }
    printf("The contents of the list are:\n");
    cur = first;
    while (cur != NULL)
    {
        print_node(cur);
        cur = cur->next;
    }
}
