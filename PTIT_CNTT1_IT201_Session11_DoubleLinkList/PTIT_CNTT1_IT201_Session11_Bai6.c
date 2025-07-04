#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void display(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}


Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }else {
        head = head -> next;
        head -> prev = NULL;
        free(temp);
        return head;
    }
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
    display(head);
    head = deleteHead(head);
    printf("Sau khi xoa: \n");
    display(head);
}