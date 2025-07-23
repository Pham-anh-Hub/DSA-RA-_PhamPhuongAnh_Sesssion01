#include <stdio.h>
#include<stdlib.h>

#define size 3

// Chi co 1 huong
void addEdge(int graph[size][size], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
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
    addEdge(graph, 1,2);
    printf("----------------------\n");
    printfMatrix(graph);
}