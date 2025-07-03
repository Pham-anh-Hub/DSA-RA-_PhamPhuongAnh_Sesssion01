#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
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

Node* arrangeNode(Node* head) {
    if (head == NULL) return NULL;
    Node* current = head; // gan bien hien tai
    int length = getLength(head); // Lay ra do dai

    Node* i = head; // Dat tam bien co vi tri laf phan tu min
    Node* temp = createNode(NULL);

    while (i != NULL){
        Node* minNode = i;
        Node* j = i -> next;
        while (j != NULL) {
            if (j -> data < minNode -> data) {
                minNode = j;
            }
            j = j -> next;
        }
        // Kiểm tra xem node hiện tại đã là node nhỏ nhất hay chưa, tránh đổi chỗ dư
        if (minNode != i) {
            temp -> data = i -> data;
            i -> data = minNode -> data;
            minNode -> data = temp -> data;
        }
        i = i -> next; // Nhảy tới node tiếp theo ở vòng lặp ngoài
    }
    return head;
}


int main() {
    Node* head = NULL;
    Node* node1 = createNode(5);
    Node* node2 = createNode(6);
    Node* node3 = createNode(3);
    Node* node4 = createNode(1);
    Node* node5 = createNode(2);

    head = node1;
    node1 ->next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    displayNode(head);
    head = arrangeNode(head);
    displayNode(head);

}