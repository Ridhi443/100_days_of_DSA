// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int adj[MAX][MAX];
    int n;
};

void initGraph(struct Graph* g, int n) {
    g->n = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 1;
}

void dfs(struct Graph* g, int node, int visited[], int stack[], int* top) {
    visited[node] = 1;
    for(int i = 0; i < g->n; i++) {
        if(g->adj[node][i] && !visited[i]) {
            dfs(g, i, visited, stack, top);
        }
    }
    stack[(*top)++] = node;
}

void topologicalSort(struct Graph* g) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = 0;
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) {
            dfs(g, i, visited, stack, &top);
        }
    }
    printf("Topological Order: ");
    while(top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int n = 6;
    initGraph(&g, n);
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);
    topologicalSort(&g);
    return 0;
}
