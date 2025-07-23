#include <stdio.h>
#include<stdlib.h>

#define SIZE 3

void addEdge(int matrix[SIZE][SIZE], int firstNode, int secondNode) {
    matrix[firstNode][secondNode] = 1;
    matrix[secondNode][firstNode] = 1;
}
void printfMatrix(int matrix[SIZE][SIZE]) {
    for (int i=0; i<SIZE;i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[3][3] = {{0}};
    int firstNode = 1;
    int secondNode = 2;
    printfMatrix(graph);
    addEdge(graph, firstNode, secondNode);
    printf("-------------------\n");
    printfMatrix(graph);
}