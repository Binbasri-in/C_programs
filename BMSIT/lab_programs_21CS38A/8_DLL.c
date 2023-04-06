/*
operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name,
Dept, Designation, Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit.
*/

// 8.DLL

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[20],name[20],dept[20],desg[20],phno[20];
    float sal;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;

// prototypes
NODE read_node();
void print_node(NODE);
NODE insert_front(NODE first);
NODE insert_rear(NODE first);
NODE delete_front(NODE first);
NODE delete_rear(NODE first);
void display(NODE first);

int main()
{
    NODE first=NULL;
    int ch;

    printf("Enter number of nodes to be created: ");
    scanf("%d",&ch);
    for (int i = 0; i < ch; i++)
    {
        first=insert_front(first);
    }

    for(;;)
    {
        printf("1. Insert at front  2. Insert at rear  3. Delete at front  4. Delete at rear  5. Display  6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first=insert_front(first);
                    break;
            case 2: first=insert_rear(first);
                    break;
            case 3: first=delete_front(first);
                    break;
            case 4: first=delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            case 6: exit(0);
        }
    }
    return 0;
}

NODE read_node()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("Enter SSN: ");
    scanf("%s",temp->ssn);
    printf("Enter name: ");
    scanf("%s",temp->name);
    printf("Enter department: ");
    scanf("%s",temp->dept);
    printf("Enter designation: ");
    scanf("%s",temp->desg);
    printf("Enter phone number: ");
    scanf("%s",temp->phno);
    printf("Enter salary: ");
    scanf("%f",&temp->sal);
    temp->rlink=NULL;
    temp->llink=NULL;
    return temp;
}

void print_node(NODE temp)
{
    printf("SSN: %s\n",temp->ssn);
    printf("Name: %s\n",temp->name);
    printf("Department: %s\n",temp->dept);
    printf("Designation: %s\n",temp->desg);
    printf("Phone number: %s\n",temp->phno);
    printf("Salary: %f\n",temp->sal);
}

NODE insert_front(NODE first)
{
    NODE temp;
    temp=read_node(); // create a new node

    if(first==NULL) // if list is empty
    {
        first=temp;
        return first;
    }

    temp->rlink=first;
    first->llink=temp;
    first=temp;

    return first; // return the first node
}

NODE insert_rear(NODE first)
{
    NODE temp,cur;
    temp=read_node(); // create a new node

    if(first==NULL) // if list is empty
    {
        first=temp;
        return first;
    }

    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;

    return first; // return the first node
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL) // if list is empty
    {
        printf("List is empty\n");
        return first;
    }

    print_node(first);
    temp=first;
    first=first->rlink;
    free(temp);
    if(first!=NULL)
        first->llink=NULL;

    return first; // return the first node
}

NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first==NULL) // if list is empty
    {
        printf("List is empty\n");
        return first;
    }

    cur=first;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur=cur->rlink;
    }
    print_node(cur);
    if(cur==first) // if there is only one node
        first=NULL;
    else
        prev->rlink=NULL;
    free(cur);

    return first; // return the first node
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL) // if list is empty
    {
        printf("List is empty\n");
        return;
    }

    printf("Contents of the list\n");
    cur=first;
    while(cur!=NULL)
    {
        print_node(cur);
        cur=cur->rlink;
    }
}


// Output
// Enter number of nodes to be created: 1
// Enter SSN: 1
// Enter Name: ali
// Enter Dept: cse
// Enter Designation: student
// Enter Salary: 1000
// Enter Phone Number: 123
// 1. Insert at front  2. Insert at rear  3. Delete at front  4. Delete at rear  5. Display  6. Exit
// Enter your choice: 5
// Contents of the list are:
// SSN: 1    Name: ali   Dept: cse    Designation: student   Salary: 1000.000000    Phone Number: 123

