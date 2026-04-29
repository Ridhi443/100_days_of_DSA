// Problem Statement: Using DFS or BFS, count number of connected components.
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

int countConnectedComponents(struct Graph* g) {
    int visited[MAX] = {0};
    int count = 0;
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) {
            dfs(g, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    struct Graph g;
    int n = 5;
    initGraph(&g, n);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 3, 4);
    int components = countConnectedComponents(&g);
    printf("Number of connected components: %d\n", components);
    return 0;
}
