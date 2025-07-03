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

// Xay dung ham hien thi
void displayNode(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

// Xay dung ham them vao cuoi
Node* insertEnd(Node* head, int data) {
    if (head == NULL) return NULL;
    // B1. Tao node moi
    Node* newNode = createNode(data);
    // B2. Duyet qua toan bo node den node cuoi cung
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    // Gan next cua node cuoi cung hien tai bang node moi hien tai
    current -> next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    displayNode(head);
    int value;
    printf("Moi nhap gia tri node can them vao: "); scanf("%d", &value);
    head = insertEnd(head, value);
    printf("\nDS say khi them: \n");
    displayNode(head);
}