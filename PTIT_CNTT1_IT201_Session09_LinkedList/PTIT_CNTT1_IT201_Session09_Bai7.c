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
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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

// Xay dung ham them phan tu va vi tri bat ky
Node* insertNode(Node* head, int index, int data) {
    if (index < 0 || index > getLenght(head)) {
        printf("\nVi tri can chen khong hop le");
        return head;
    }

    // Duyet đến vị trí kề cận với vị trí cần chèn
    Node* current = head;
    for (int i = 0; i < index-2; i++) {
        current = current -> next;
    }
    // Tao ra 1 node moi
    Node* newNode = createNode(data);

    // Cập nhật chèn node vào giữa bằng cách cập nhật lại con trỏ
    // Lưu node bên cạnh vào 1 biến
    Node* nextNode = current -> next;
    current -> next = newNode;
    newNode -> next = nextNode;

    return head;
}

void display(Node* head) {
    Node* current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL");
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
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    display(head);
    // Lay gia tri node can chen
    int value, index;
    printf("\nMoi nhap vi tri can them (khac dau/cuoi): ");scanf("%d", &index);
    printf("\nMoi nhap du lieu can them: ");scanf("%d", &value);


    insertNode(head, index, value);
    printf("\nSau khi them: \n");
    display(head);


}