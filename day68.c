// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
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

void topologicalSort(struct Graph* g) {
    int inDegree[MAX] = {0};
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            if(g->adj[i][j]) {
                inDegree[j]++;
            }
        }
    }
    int queue[MAX];
    int front = 0, rear = 0;
    for(int i = 0; i < g->n; i++) {
        if(inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int count = 0;
    printf("Topological Order: ");
    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        for(int v = 0; v < g->n; v++) {
            if(g->adj[u][v]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    if(count != g->n) {
        printf("\nGraph has a cycle\n");
    } else {
        printf("\n");
    }
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
