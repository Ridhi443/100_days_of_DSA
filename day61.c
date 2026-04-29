// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v, int isDirected) {
    adjMatrix[u][v] = 1;
    if(!isDirected) {
        adjMatrix[v][u] = 1;
    }
}

void printGraph(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}