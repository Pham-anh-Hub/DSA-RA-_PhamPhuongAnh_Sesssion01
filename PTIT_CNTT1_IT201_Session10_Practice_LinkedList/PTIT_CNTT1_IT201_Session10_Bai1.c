#include <stdio.h>
#include <stdlib.h>

// Khoi tao cau truc cua 1 phan tu
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Xay dung ham tao moi Node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    Node* head = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
}