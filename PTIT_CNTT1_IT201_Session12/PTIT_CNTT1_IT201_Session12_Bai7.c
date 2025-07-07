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
// Ham bieu dien danh sach
void displayList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current != NULL) {
        printf("%d", current -> data);
        if (current -> next != NULL) {
            printf(" <-> ");
        }else {
            printf(" -> ");
        }
        current = current -> next;
    }
    printf("NULL\n");
}

// Lay duoc length
int getLength(Node* head) {
    if (head == NULL) return 0;
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

int main() {
    Node* head;
    Node* node1 = createNode(6);
    Node* node2 = createNode(2);
    Node* node3 = createNode(8);
    Node* node4 = createNode(3);
    Node* node5 = createNode(7);
    Node* node6 = createNode(9);

    head = node1;
    head -> next = node2;
    node2 -> prev = node1;

    node2 -> next = node3;
    node3 -> prev = node2;

    node3 -> next = node4;
    node4 -> prev = node3;

    node4 -> next = node5;
    node5 -> prev = node4;

    node5 -> next = node6;
    node6 -> prev = node5;

    int midNode = getLength(head) / 2 + 1;
    Node* current = head;
    for (int i = 1; i < midNode; i++) {
        current = current -> next;
    }
    displayList(head);
    printf("\nNode %d: %d", midNode, current -> data);
}




