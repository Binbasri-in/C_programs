#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    char usn[10];
    char name[20];
    char branch[20];
    int sem;
    char phno[20];
    struct node *next;
} node;

typedef node* NODE;

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
        first = insert_front(first);
    }
    for(;;)
    {
        printf("1. Insert front\n2. Insert rear\n3. Delete front\n4. Delete rear\n5. Display\n6. Exit\n");
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

// function to read a node
NODE read_node()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(node));
    printf("Enter the USN: ");
    scanf("%s", temp->usn);
    printf("Enter the name: ");
    scanf("%*c%[^\n]", temp->name);
    printf("Enter the branch: ");
    scanf("%s", temp->branch);
    printf("Enter the semester: ");
    scanf("%d", &temp->sem);
    printf("Enter the phone number: ");
    scanf("%s", temp->phno);
    temp->next = NULL;
    return temp;
}

// function to print a node
void print_node(NODE temp)
{
    printf("USN: %s\n", temp->usn);
    printf("Name: %s\n", temp->name);
    printf("Branch: %s\n", temp->branch);
    printf("Semester: %d\n", temp->sem);
    printf("Phone number: %s\n", temp->phno);
}

// function to insert a node at the front
NODE insert_front(NODE first)
{
    NODE temp;
    temp = read_node();
    temp->next = first;
    first = temp;
    return first;
}

// function to insert a node at the rear
NODE insert_rear(NODE first)
{
    NODE temp, cur;
    temp = read_node();
    if (first == NULL)
    {
        first = temp;
        return first;
    }
    cur = first;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    return first;
}

// function to delete a node from the front
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    printf("Deleted node is:\n");
    print_node(temp);
    first = first->next;
    free(temp);
    return first;
}

// function to delete a node from the rear
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    if (first->next == NULL)
    {
        printf("Deleted node is:\n");
        print_node(first);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted node is:\n");
    print_node(cur);
    prev->next = NULL;
    free(cur);
    return first;
}

// function to display the list and count the number of nodes
void display(NODE first)
{
    NODE cur;
    int count = 0;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Contents of the list are:\n");
    cur = first;
    while (cur != NULL)
    {
        print_node(cur);
        cur = cur->next;
        count++;
    }
    printf("Number of nodes in the list = %d\n", count);
}