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


Node* deleteAt(Node* head, int index) {
    if (head == NULL) return NULL;
    if (index == 0) {
        // Xoa o dau
        head = head -> next;
        head -> next -> prev = NULL;
        return head;
    }else if (index == getLength(head)) {
        // Xoa o cuoi
        Node* current = head;
        while (current -> next != NULL) {
            current = current->next;
        }
        current = current -> prev; // Gán node hiện tại là node prev
        current -> next = NULL;
        return head;
    }else {
        // Them vao vi tri index
        Node* current = head;
        for (int i=0; i<index - 1; i++) {
            current = current->next;
        }
        printf("\ncurrent : %d <-> \n", current->data);
        Node* prev = current->prev; // 6
        Node* next = current->next; // 7
        if (prev != NULL && next != NULL) {
            current -> prev -> next = next;
            current -> next -> prev = prev;
        }
        free(current);
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

    int index;
    printf("Nhap vi tri can xoa: ");scanf("%d", &index);
    head = deleteAt(head, index);
    // printf("\nSau khi xoa: \n");
    display(head);
}