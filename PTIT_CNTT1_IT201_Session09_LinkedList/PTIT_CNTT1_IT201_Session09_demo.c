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

void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
}

//Xay dung ham them phan tu vao cuoi
Node* insert(Node* head) {
    // B1. Khoi tao phan tu can duoc them moi
    Node* newNode = createNode(4);

    // Kiem tra: Neu danh sach trong -> gan truc tiep phan tu head bang phan tu moi do
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // B2. Duyet den phan tu cuoi cung
    Node* lastNode = head;
    while (lastNode -> next != NULL) { // Tuc la khi lastNode laf phan tu cuoi cung
        head = head -> next;
    }
    // B3. Tien hanh cap nhat cac con tro can thiet

    // B4. Tra ve danh sach lien ket don moi
}

// Xoa phan tu o cuoi
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        return head;
    }
    // TH danh sach chi co 1 phan tu
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

    // TH danh sach co nhieu hon 1 phan tu
    // Duyet den phan tu gan cuoi
    Node* secondLastNode = head;
    while (secondLastNode -> next -> next != NULL) {
        secondLastNode = secondLastNode -> next;
    }
    // Cap nhat cac con tro can thiet
    secondLastNode -> next = NULL;
    return head;
}



// Xay dung ham khoi tao danh sach lien ket don
int main() {
    // Khoi tao cac node
    Node* head = NULL;

    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
        ;
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;

    display(head);
}