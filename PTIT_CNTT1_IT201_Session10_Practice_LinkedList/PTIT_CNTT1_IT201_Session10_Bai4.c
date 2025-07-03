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

// Lay do dai cua danh sach
int getLength(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

// Xay dung ham xoa phan tu cuoi mang
Node* deleteEnd(Node* head) {
    if (getLength(head) <= 0) return NULL;
    Node* current = head;
    // Duyet den phan tu o cuoi mang
    while (current -> next -> next != NULL) {
        current = current -> next;
    }
    printf("%d ", current -> data);
    // Gan cho next cua node ke node cuoi = NULL;
    current -> next = NULL;
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
    head = deleteEnd(head);
    printf("\nDS sau khi xoa: \n");
    displayNode(head);
}