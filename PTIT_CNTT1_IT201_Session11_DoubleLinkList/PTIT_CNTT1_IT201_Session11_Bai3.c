#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

// Xay dung ham search
bool searchNode(Node* head, int value) {
    if (head == NULL) {
        return false;
    }
    Node* current = head;
    while (current != NULL) {
        if (current -> data == value) {
            return true;
        }
        current = current -> next;
    }
    return false;
}



int main() {
    Node* head = NULL;
    Node* node1 = createNode(6);
    Node* node2 = createNode(2);
    Node* node3 = createNode(7);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    head = node1;
    head -> next = node2;
    node2 -> prev = head;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;
    int target;
    printf("Moi nhap gia tri can tim kiem: "); scanf("%d", &target);
    if (searchNode(head, target)) {
        printf("\nTrue");
    }else {
        printf("\nFalse");
    }
}
