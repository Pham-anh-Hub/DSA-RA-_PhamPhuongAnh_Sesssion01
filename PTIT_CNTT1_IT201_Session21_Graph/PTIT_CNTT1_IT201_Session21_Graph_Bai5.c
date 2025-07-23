#include <stdio.h>
#include <stdlib.h>

// Ktao cau tstruct danh sach lien ket don
typedef struct Node {
    int data;
    struct Node *next;
}Node;
// Ham tao moi node
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = data;
    newNode -> next = NULL;
    return newNode;
}

// Tao 1 cau truc graph
typedef struct Graph {
    int numVertex;
    Node **adjList;
}Graph;

// Tao moi graph
Graph *createGraph(int numVertex) {
    Graph *newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph -> numVertex = numVertex;
    newGraph -> adjList = (Node**)malloc(numVertex * sizeof(Node*));
    for (int i = 0; i < numVertex; i++) {
        newGraph -> adjList[i] = NULL;
    }
    return newGraph;
}

// Tao 1 danh sach lien ket co so node la so dinh cua do thi

// Ktao ham addEdge
void addEdge(Graph *graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Khi do thi la vo huong
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph -> numVertex; i++) {
        Node *temp = graph -> adjList[i];
        // printf("%d -> ", i); // Dinh goc
        while (temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph *graph = createGraph(3);
    addEdge(graph, 1, 2);
    // addEdge(graph, 0, 1);
    printGraph(graph);
    return 0;
}



