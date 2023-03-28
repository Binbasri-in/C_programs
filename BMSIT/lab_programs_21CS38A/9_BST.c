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

NODE delete_node(NODE root, int key)
{
    NODE cur, prev, child, succ;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL && cur->data != key)
    {
        prev = cur;
        if (key < cur->data)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (cur == NULL)
    {
        printf("Key not found\n");
        return root;
    }
    if (cur->llink == NULL)
        child = cur->rlink;
    else if (cur->rlink == NULL)
        child = cur->llink;
    else
    {
        succ = cur->rlink;
        while (succ->llink != NULL)
            succ = succ->llink;
        succ->llink = cur->llink;
        child = cur->rlink;
    }
    if (prev == NULL)
        root = child;
    else if (cur == prev->llink)
        prev->llink = child;
    else
        prev->rlink = child;
    free(cur);
    return root;
}

int main()
{
    NODE root = NULL;
    int choice, item, key;
    for (;;)
    {
        printf("1. Insert 2. Delete  3. Search  4. Inorder  5. Preorder  6. Postorder  7. Exit\n");
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
            printf("Enter the item to be deleted: ");
            scanf("%d", &key);
            root = delete_node(root, key);
            break;
        case 3:
            printf("Enter the item to be searched: ");
            scanf("%d", &key);
            root = search(root, key);
            if (root != NULL)
                printf("Key found\n");
            else
                printf("Key not found\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            preorder(root);
            printf("\n");
            break;
        case 6: 
            postorder(root);
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
