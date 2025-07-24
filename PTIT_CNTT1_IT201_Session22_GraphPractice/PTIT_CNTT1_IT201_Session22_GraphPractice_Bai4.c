//
// Created by DELL on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int **matrix;
    int size;
}Graph;

Graph *createGraph(int size) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = size;
    graph->matrix = (int **)malloc(size * sizeof(int *));
    return graph;
};

void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

int countEdge(Graph *graph) {
    int count = 0;
    for (int i = 0; i < graph->size; i++) {
        for (int j = i+1; j < graph->size; j++) {
            if (graph->matrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    printf("Nhap so dinh cua san pham:  ");
    scanf("%d", &n);
    Graph *graph = createGraph(n);
    for (int i = 0; i < n; i++) {
        graph -> matrix[i] = (int *)malloc(n*sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph->matrix[i][j]);
        }
    }
    printf("So canh: %d", countEdge(graph));
}