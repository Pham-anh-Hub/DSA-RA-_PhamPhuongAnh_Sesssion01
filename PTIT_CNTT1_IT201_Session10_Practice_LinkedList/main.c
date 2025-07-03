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

// Xay dung ham in ra cac node
Node* displayNode(Node* head) {
    if (head == NULL) return NULL;

    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL");
}

// Xay dung ham lay do dai ds
int getLength(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

// Xay dung ham them moi vao dau danh sach
Node* insertStart(Node* head) {
    // Kiem tra node dau tien
    if (head == NULL) return NULL;
    // Tao node moi
    Node* newNode = createNode(10);
    // Gan next cua node mới = node head hiện tại. Tức là newNode sẽ là node head mới
    newNode -> next = head;
    // Trả về node mới
    return newNode;
}

// Xay dung ham them moi vao cuoi danh sach
Node* insertEnd(Node* head, int data) {
    if (head == NULL) return NULL;

    // Kiem tra danh sach co rong hay khong


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

// Xay dung ham them moi vao vi tri bat ki
Node* insertAt(Node* head, int data, int index) {
    if (head == NULL) return NULL;
    if (index == 0) return insertStart(head);
    if (index == getLength(head)) insertEnd(head, data);

    Node* current  = head;
    // Tiến hành duyệt đến vị trí kề cận với vị trí cần chèn
    for (int i=0; i<index-2; i++) {
        current = current -> next;
    }
    // Sau khi lay dung vi tri, tao node moi
    Node* newNode = createNode(data);
    // Luu node canh node ke dan vao 1 bien
    Node* nextNode = current -> next;
    // Gan node ke voi newNode = nextNode
    current -> next = newNode;
    // Gan nextNode bang node o vi tri cu
    newNode -> next = nextNode;
    return head;
}

int main() {

    Node* head = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;


    displayNode(head);
    head = insertAt(head, 11, 2);
    head = insertAt(head, 13, 3);
    head = insertEnd(head, 15);
    printf("\nSau khi them: \n");
    displayNode(head);
}
