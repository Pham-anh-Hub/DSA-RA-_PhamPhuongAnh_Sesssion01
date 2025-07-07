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
// Do dai danh sach
int getLength(Node* head) {
    if (head == NULL) return 0;
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

// Xay dung ham xoa phan tu o dau
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}
// Xay dung ham xoa phan tu cuoi
Node* deleteEnd(Node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    // printf("current -> %d\n", current -> data);
    current = current -> prev;
    current -> next = NULL;
    return head;
}
//Xoa phan tu o vi tri bat ky
Node* deleteAt(Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        return deleteHead(head);
    }else if (pos == getLength(head)) {
        return deleteEnd(head);
    }else {
        Node* current = head;
        for (int i = 1; i < pos-1; i++) {
            current = current -> next;
        }
        printf("current -> %d\n", current -> data);
        current -> next = current -> next -> next;
        current -> next -> prev = current -> prev;
        return head;
    }
}

int main() {
    Node* head = NULL;
    Node* node1 = createNode(5);
    Node* node2 = createNode(3);
    Node* node3 = createNode(8);
    Node* node4 = createNode(5);
    Node* node5 = createNode(7);

    head = node1;
    head -> next = node2;
    node2 -> prev = node1;

    node2 -> next = node3;
    node3 -> prev = node2;

    node3 -> next = node4;
    node4 -> prev = node3;

    node4 -> next = node5;
    node5 -> prev = node4;

    displayList(head);
    Node* current = head;
    int value, i=1;
    printf("\nNhap gia tri phan tu can xoa: "); scanf("%d", &value);
    while (i<= getLength(head)) {
        if (current -> data == value) {
            printf("%d \n", i);
            head = deleteAt(head, i);
            current = head;
            i=1;
            continue;
            // Gan lai head va index xoa --> tránh bỏ sót node cần xóa
        }
        i++;
        current = current -> next;
    }
    displayList(head);
}