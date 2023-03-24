// Breadth-first search (BFS) and depth-first search (DFS) algorithms on graph

#include <stdio.h>
#include <stdlib.h>

// global variables
int visited[20], n, adj[20][20];

// prototypes
void bfs(int);
void dfs(int);

int main()
{
    int ch, i, source, j, flag;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("1. Breadth First Search  2. Depth First Search  3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1: printf("Enter starting vertex for BFS: ");
                scanf("%d", &source);
                bfs(source);
                break;
        case 2: printf("Enter starting vertex for DFS: ");
                scanf("%d", &source);
                dfs(source);
                break;
        case 3: exit(0);
    }
    // nodes are reachable from source
    flag = 0;

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("%d is not reachable", i);
            flag = 1;
        }
        else
            printf("%d is reachable", i);
    }
    if (flag == 0)
        printf("All nodes are reachable");
    return 0;
}

void bfs(int source)
{
    int queue[20], front = 0, rear = -1, i, u;
    
    queue[++rear] = source;
    visited[source] = 1;
    while (front <= rear)
    {
        u = queue[front++];
        for (i = 0; i < n; i++)
        {
            if (adj[u][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int source)
{
    int stack[20], top = -1, i, u;

    stack[++top] = source;
    visited[source] = 1;
    while (top != -1)
    {
        u = stack[top--];
        for (i = 0; i < n; i++)
        {
            if (adj[u][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

