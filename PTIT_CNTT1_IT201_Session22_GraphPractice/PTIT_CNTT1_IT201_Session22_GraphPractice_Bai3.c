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
}

// Danh sach lien ket
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}


void printConnection(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("%d:  ", i);
        for (int j = 0; j < graph->size; j++) {
            if (graph -> matrix[i][j] == 1) {
                printf("%d -> ", j);
            }
        }
        printf("NULL \n");
    }
}

int main() {
    int n;
    printf("Nhap vao so luong dinh cua do thi: ");
    scanf("%d", &n);
    Graph *graph = createGraph(n);
    printf("Nhap vao cac gia tri cua do thi: \n");
    for (int i = 0; i < n; i++) {
        graph -> matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph -> matrix[i][j]);
        }
    }
    printConnection(graph);

}