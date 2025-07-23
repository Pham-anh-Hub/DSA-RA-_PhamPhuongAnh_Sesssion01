#include <stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct Graph {
    int *vertex;
    int **matrix;
    int size;
}Graph;

Graph *createGraph(int size) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph -> size = size;
    graph -> vertex = (int*)malloc(sizeof(int)*size);
    graph -> matrix = (int**)calloc(size, sizeof(int));
    for (int i=0; i<size; i++) {
        graph -> matrix[i] = (int*)calloc(size, sizeof(int));
    }
    for (int i=0; i<size; i++) {
        graph -> vertex[i] = i ;
    }
    return graph;
}
void addEdge(Graph *graph, int firstNode, int secondNode) {
    graph -> matrix[firstNode][secondNode] = 1;
}

void printfMatrix(Graph *graph) {
    for (int i=0; i<graph->size; i++) {
        for (int j=0; j<graph->size; j++) {
            printf("%d  ", graph -> matrix[i][j]);
        }
        printf("\n");
    }
}
void printConnect(Graph *graph) {
    for (int i=0; i<graph->size; i++) {
        printf("%d: ", graph ->vertex[i]);
        for (int j=0; j<graph ->size; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d",graph->vertex[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph(SIZE);
    printfMatrix(graph);
    addEdge(graph, 1,2);
    printf("------------------\n");
    printfMatrix(graph);
    printf("Cac lien ket: \n");
    printConnect(graph);
}