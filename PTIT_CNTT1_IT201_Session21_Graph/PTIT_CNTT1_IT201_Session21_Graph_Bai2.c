#include <stdio.h>
#include<stdlib.h>

#define size 4

void addEdge(int graph[size][size], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printfMatrix(int graph[size][size]) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}



int main() {
    int graph[size][size] = {{0}};
    printfMatrix(graph);
    addEdge(graph, 0,1);
    addEdge(graph, 0,2);
    addEdge(graph, 1,2);
    addEdge(graph, 2,3);
    printf("----------------------\n");
    printfMatrix(graph);
}