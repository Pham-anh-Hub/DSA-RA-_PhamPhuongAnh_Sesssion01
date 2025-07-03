#include <stdio.h>
#include <stdlib.h>

// Khoi tao Linklist
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Xay dung ham tao node moi
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int getLength(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

int main() {
    Node* head = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);
    head = node1;
    node1-> next = node2;
    node2-> next = node3;
    node3-> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    Node* current = head;
    int index = (getLength(head) / 2) + 1, i=0;
        for (int i = 0; i < index-1; i++) {
            current = current -> next;
        }
        printf("node %d: %d", index, current -> data);
}

