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

// Xay dung ham xoa phan tu o vi tri bat ky
Node* deleteNode(Node* head, int index) {
    // Kiem tra xem có rỗng không
    if (head == NULL) return NULL;

    Node* current = head;
    // Duyet den node can xoa
    for (int i=0; i<index-2; i++) {
        current = current -> next;
    }
    // Gan node do vao 1 bien tam
    Node* temp = current->next;
    if (temp == NULL) return head; // Không có node để xóa
    current->next = temp->next; // Nối node hiện tại với node sau node bị xóa
    free(temp);

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

    int index;
    printf("\nMoi nhap vi tri can xoa(khac dau/cuoi): "); scanf("%d", &index);
    head = deleteNode(head, index);
    printf("\nSau khi xoa: \n");
    display(head);


}