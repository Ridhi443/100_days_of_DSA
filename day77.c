// Problem Statement: Using BFS or DFS, check if the entire graph is connected.
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
    g->adj[v][u] = 1;
}

void dfs(struct Graph* g, int node, int visited[]) {
    visited[node] = 1;
    for(int i = 0; i < g->n; i++) {
        if(g->adj[node][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

int isConnected(struct Graph* g) {
    int visited[MAX] = {0};
    dfs(g, 0, visited);
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) return 0;
    }
    return 1;
}

int main() {
    struct Graph g;
    int n = 5;
    initGraph(&g, n);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    if(isConnected(&g)) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }
    return 0;
}