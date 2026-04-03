#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[100]; // adjacency list

struct Node* createNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v) {
    // add v to u
    struct Node* temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    // for undirected graph, also add u to v
    temp = createNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize lists
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}