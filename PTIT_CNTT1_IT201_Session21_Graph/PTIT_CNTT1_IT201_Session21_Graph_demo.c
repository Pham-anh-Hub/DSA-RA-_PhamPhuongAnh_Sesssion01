#include <stdio.h>
#include <stdlib.h>

// Xay dung cau truc do thi
typedef struct Graph {
    int V;
    int **adjMatrix;
}Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph -> V = V;
    // Cap phat bo nho cho ma tran (Mang 2 chieu)
    graph -> adjMatrix = (int **)malloc(V * sizeof(int));
    for (int i=0; i<V; i++) {
        // Cap phat bo nho cho can mang con ben trong ma tran, va gan gtri cho cac ptu trong mang con do = 0
        graph -> adjMatrix[i] = (int*)calloc(V,sizeof(int));
    }
    return graph;
}

// Thiet lap canh cho do thi
void addEdge(Graph *graph, int src, int dest) {
    graph -> adjMatrix[src][dest] = 1;
    graph -> adjMatrix[dest][src] = 1;
}

// Ham in do thi
void printMatrix(Graph *graph) {
    for (int i=0; i<graph->V; i++) {
        for (int j=0; j<graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
    }
}

void printfConnect(Graph *graph) {
    for (int i=0; i<graph->V; i++) {
        printf("%d: ", graph->adjMatrix[i]);
        for (int j=0; j<graph->V; j++) {
            if (graph -> adjMatrix[i][j] == 1) {
                printf("%d ", graph -> adjMatrix[i][j]);
            }
        }
    }
}






// void printfMatrix(int matrix[4][4], int size) {
//     for (int i=0; i<size; i++) {
//         for (int j = 0; j<size; j++) {
//             printf("%d  ",matrix[i][j]);
//         }
//         printf("\n");
//     }
// }
// void printfConnetctMatrix(int matrix[4][4], char verticle[4], int size) {
//     for (int i=0; i<size; i++) {
//         printf("%c: ", verticle[i]);
//         for (int j = 0; j<size; j++) {
//             if (matrix[i][j] == 1) {
//                 printf("%c ", verticle[j]);
//             }
//         }
//         printf("\n");
//     }
// }
// int main() {
//     // khai bao 4 dinh
//     char vextexData[4] = {'A', 'B', 'C', 'D'};
//     // Khai bao mang 2 chieu
//     int matrix[4][4] = {
//         {0,1,1,1},
//         {1,0,1,0},
//         {1,1,0,0},
//         {1,0,0,0},
//     };
//     printf("Vertex Data: \n");
//     for (int i=0; i<4; i++) {
//         printf("%c", vextexData[i]);
//     }
//     printf("\n");
//     printfMatrix(matrix, 4);
//     printf("\n");
//     printfConnetctMatrix(matrix,vextexData,4);
// }
