Problem: Detect cycle in directed graph using DFS and recursion stack.


#include <stdio.h>

int n;
int adj[100][100];
int visited[100], recStack[100];

int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i])
        {
            if(!visited[i] && dfs(i))
                return 1;
            else if(recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int main()
{
    int i, j, hasCycle = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for(i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
