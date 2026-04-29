// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

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

void addEdge(struct Graph* g, int u, int v, int w) {
    g->adj[u][v] = w;
}

void dijkstra(struct Graph* g, int source) {
    int dist[MAX];
    int visited[MAX] = {0};
    for(int i = 0; i < g->n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    for(int count = 0; count < g->n - 1; count++) {
        int min = INF, u = -1;
        for(int i = 0; i < g->n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        visited[u] = 1;
        for(int v = 0; v < g->n; v++) {
            if(!visited[v] && g->adj[u][v] && dist[u] != INF && dist[u] + g->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }
    printf("Shortest distances from source %d:\n", source);
    for(int i = 0; i < g->n; i++) {
        if(dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int n = 5;
    initGraph(&g, n);
    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 3, 5);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 1, 3, 2);
    addEdge(&g, 2, 4, 4);
    addEdge(&g, 3, 1, 3);
    addEdge(&g, 3, 2, 9);
    addEdge(&g, 3, 4, 2);
    addEdge(&g, 4, 0, 7);
    addEdge(&g, 4, 2, 6);
    dijkstra(&g, 0);
    return 0;
}
