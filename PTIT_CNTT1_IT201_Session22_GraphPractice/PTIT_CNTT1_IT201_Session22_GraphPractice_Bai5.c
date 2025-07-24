//
// Created by DELL on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int size;
    int **matrix;
}Graph;

Graph *createGraph(int size) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = size;
    graph->matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        graph -> matrix[i] = (int *)calloc(size,sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph,int src, int dest) {
    graph -> matrix[src][dest] = 1;
    graph -> matrix[dest][src] = 1;
}

int countVertices(Graph *graph, int target) {
    int count = 0;
        for (int j = 0; j < graph->size; j++) {
            if (graph -> matrix[target][j] == 1) {
                count++;
            }
    }
    return count;
}

int main() {
    int n,v;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);
    Graph *graph = createGraph(n);
    while (v--) {
        int first,second;
        scanf("%d %d", &first, &second);
        addEdge(graph,first,second);
    }
    int target;
    printf("Nhap dinh muon kiem tra: "); scanf("%d", &target);
    printf("So dinh ke voi %d la: %d",target, countVertices(graph, target));
}