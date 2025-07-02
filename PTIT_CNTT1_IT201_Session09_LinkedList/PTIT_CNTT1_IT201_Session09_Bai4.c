#include <stdio.h>
#include <stdlib.h>

// Khoi tao cau truc 1 phan tu

typedef struct Node {
    int data; // Du lieu
    struct Node* next; // Con tro tro den node tiep theo
}Node;

// Xay dung ham khoi tao 1 phan tu
Node* createNode(int data) {
    //B1. Khoi tao node moi va cap phat vung nho
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); // Cấp phat vung nhớ cho node mới đó
    // B2. Gan gia tri cho node moi
    node -> data = data;
    // Gan con tro
    node -> next = NULL;
    return node;
}

int getLenght(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}


// Xay dung ham khoi tao danh sach lien ket don
int main() {
    // Khoi tao cac node
    Node* head = NULL;

    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(5);
    Node* node5 = createNode(7);
        ;
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    printf("Danh sach lien ket co %d phan tu", getLenght(head));
}