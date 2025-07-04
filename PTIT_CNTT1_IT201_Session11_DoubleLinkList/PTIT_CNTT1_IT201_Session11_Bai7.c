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

int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}


Node* insertAt(Node* head, int value, int index) {
    if (head == NULL) return NULL;
    Node* newNode = createNode(value);
    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }else if (index == getLength(head)) {
        // Them vao cuoi
        Node* current = head;
        while (current -> next != NULL) {
            current = current->next;
        }
        newNode -> prev = current;
        newNode -> next = NULL;
        return head;
    }else {
        // Them vao vi tri index
        Node* current = head;
        for (int i=0; i<index - 1; i++) {
            current = current->next;
        }
        printf("%d <-> ", current->data);
        newNode -> prev = current -> prev;
        newNode -> next = current;
        current -> prev -> next = newNode;
        current -> prev = newNode;
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

    int value, index;
    printf("Nhap gia tri can them: ");scanf("%d", &value);
    printf("Nhap vi tri can them: ");scanf("%d", &index);
    head = insertAt(head, value, index);
    printf("\nSau khi them: \n");
    display(head);
}