Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.


#include <stdio.h>

int visited[100];

int dfs(int v, int parent, int adj[100][100], int n)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1)
        {
            if(visited[i] == 0)
            {
                if(dfs(i, v, adj, n))
                    return 1;
            }
            else if(i != parent)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int adj[100][100];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, -1, adj, n))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
