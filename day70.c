// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

struct Edge {
    int u, v, w;
};

struct Graph {
    struct Edge edges[MAX];
    int e, n;
};

void initGraph(struct Graph* g, int n, int e) {
    g->n = n;
    g->e = e;
}

void addEdge(struct Graph* g, int i, int u, int v, int w) {
    g->edges[i].u = u;
    g->edges[i].v = v;
    g->edges[i].w = w;
}

void bellmanFord(struct Graph* g, int source) {
    int dist[MAX];
    for(int i = 0; i < g->n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    for(int i = 1; i < g->n; i++) {
        for(int j = 0; j < g->e; j++) {
            int u = g->edges[j].u;
            int v = g->edges[j].v;
            int w = g->edges[j].w;
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // check for negative cycles
    int negCycle = 0;
    for(int j = 0; j < g->e; j++) {
        int u = g->edges[j].u;
        int v = g->edges[j].v;
        int w = g->edges[j].w;
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            negCycle = 1;
            break;
        }
    }
    if(negCycle) {
        printf("Graph contains negative weight cycle\n");
    } else {
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
}

int main() {
    struct Graph g;
    int n = 5, e = 8;
    initGraph(&g, n, e);
    addEdge(&g, 0, 0, 1, -1);
    addEdge(&g, 1, 0, 2, 4);
    addEdge(&g, 2, 1, 2, 3);
    addEdge(&g, 3, 1, 3, 2);
    addEdge(&g, 4, 1, 4, 2);
    addEdge(&g, 5, 3, 2, 5);
    addEdge(&g, 6, 3, 1, 1);
    addEdge(&g, 7, 4, 3, -3);
    bellmanFord(&g, 0);
    return 0;
}
