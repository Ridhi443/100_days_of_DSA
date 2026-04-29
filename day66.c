// Problem: Detect cycle in directed graph using DFS and recursion stack.
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

int dfs(struct Graph* g, int node, int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;
    for(int i = 0; i < g->n; i++) {
        if(g->adj[node][i]) {
            if(!visited[i] && dfs(g, i, visited, recStack)) {
                return 1;
            } else if(recStack[i]) {
                return 1;
            }
        }
    }
    recStack[node] = 0;
    return 0;
}

int hasCycle(struct Graph* g) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};
    for(int i = 0; i < g->n; i++) {
        if(!visited[i]) {
            if(dfs(g, i, visited, recStack)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    struct Graph g;
    int n = 4;
    initGraph(&g, n);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0); // cycle
    addEdge(&g, 1, 3);
    if(hasCycle(&g)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle\n");
    }
    return 0;
}
