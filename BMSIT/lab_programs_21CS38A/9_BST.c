// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;

NODE insert_node(NODE root, int item)
{
    NODE temp, prev, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->rlink = NULL;
    temp->llink = NULL;
    if (root == NULL)
        return temp;

    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->data)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->data)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->data);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->data);
}

NODE search(NODE root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->llink, key);
    else
        return search(root->rlink, key);
}


int main()
{
    NODE root = NULL;
    int choice, item, key;
    for (;;)
    {
        printf("1. Insert  2. Search  3. Inorder  4. Preorder  5. Postorder  6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            root = insert_node(root, item);
            break;
        case 2:
            printf("Enter the item to be searched: ");
            scanf("%d", &key);
            root = search(root, key);
            if (root != NULL)
                printf("Key found\n");
            else
                printf("Key not found\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            preorder(root);
            printf("\n");
            break;
        case 5: 
            postorder(root);
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
    return 0;
}


// Output
// 1. Insert 2. Delete  3. Search  4. Inorder  5. Preorder  6. Postorder  7. Exit
// Enter your choice: 1
// Enter the item to be inserted: 50
// 1. Insert 2. Delete  3. Search  4. Inorder  5. Preorder  6. Postorder  7. Exit
// Enter your choice: 1
// Enter the item to be inserted: 30
// 1. Insert 2. Delete  3. Search  4. Inorder  5. Preorder  6. Postorder  7. Exit
// Enter your choice: 4
// 30 50
// 1. Insert 2. Delete  3. Search  4. Inorder  5. Preorder  6. Postorder  7. Exit
// Enter your choice: 5
// 50 30
