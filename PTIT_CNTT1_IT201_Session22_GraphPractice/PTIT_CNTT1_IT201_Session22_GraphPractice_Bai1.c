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
    for (int i = 0; i < size; i++) {
        graph->matrix[i] = (int *)calloc(size,sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int n;
    printf("Nhap vao so luong dinh cua do thi: ");
    scanf("%d", &n);
    Graph *graph = createGraph(n);
    int firstNode, secondNode;
    while (scanf("%d %d", &firstNode, &secondNode) == 2) {
        addEdge(graph, firstNode, secondNode);
    }
    printGraph(graph);

}