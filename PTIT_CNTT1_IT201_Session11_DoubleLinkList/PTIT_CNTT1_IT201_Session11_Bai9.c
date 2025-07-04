#include <stdio.h>
#include <stdlib.h>

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
void displayList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    int index = 1;
    printf("NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}
void reverseList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    printf("NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current -> data);
        current = current -> prev;
    }
    printf("NULL\n");
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
    displayList(head);
    printf("Sau khi dao nguoc: \n");
    reverseList(head);
}
