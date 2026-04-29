// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int adj[MAX][MAX];
    int visited[MAX];
    int n;
};

void initGraph(struct Graph* g, int n) {
    g->n = n;
    for(int i = 0; i < n; i++) {
        g->visited[i] = 0;
        for(int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

int dfs(struct Graph* g, int node, int parent) {
    g->visited[node] = 1;
    for(int i = 0; i < g->n; i++) {
        if(g->adj[node][i]) {
            if(!g->visited[i]) {
                if(dfs(g, i, node)) return 1;
            } else if(i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(struct Graph* g) {
    for(int i = 0; i < g->n; i++) {
        if(!g->visited[i]) {
            if(dfs(g, i, -1)) return 1;
        }
    }
    return 0;
}

int main() {
    struct Graph g;
    int n = 5; // example
    initGraph(&g, n);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0); // cycle
    if(hasCycle(&g)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle\n");
    }
    return 0;
}
