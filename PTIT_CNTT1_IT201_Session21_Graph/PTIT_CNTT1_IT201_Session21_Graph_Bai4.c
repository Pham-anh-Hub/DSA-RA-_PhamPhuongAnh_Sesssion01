#include<stdio.h>
#include<stdlib.h>

#define size 3

void addEdge(int graph[size][size], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

void printMatrix(int graph[size][size]) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[size][size] = {{0}};
    printMatrix(graph);
    addEdge(graph,1,0);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    printf("--------------------\n");
    printMatrix(graph);

}