// Breadth-first search (BFS) and depth-first search (DFS) algorithms on graph

#include <stdio.h>
#include <stdlib.h>

// global variables
int visited[20] = {0}; 
int n, adj[20][20];

// prototypes
void bfs(int);
void dfs(int);

int main()
{
    int ch, i, source, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);


    printf("Enter starting vertex for BFS: ");
    scanf("%d", &source);
    bfs(source);
             
    // nodes are reachable from source
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("%d is not reachable\n", i);
            flag = 1;
        }
        else
            printf("%d is reachable\n", i);
    }
    if (flag == 0)
        printf("All nodes are reachable, so it is connected graph\n");
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


// Output
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 0
// 1 0 0 1
// 1 0 0 1
// 0 0 0 0
// 1. Breadth First Search  2. Depth First Search  3. Exit
// Enter your choice: 1
// Enter starting vertex for BFS: 0
// 0 is reachable
// 1 is reachable
// 2 is reachable
// 3 is not reachable
