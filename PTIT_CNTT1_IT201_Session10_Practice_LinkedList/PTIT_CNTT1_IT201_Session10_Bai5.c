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
    if (head == NULL) return 0;
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

    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

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

// Xay dung ham xoa phan tu o dau ds
Node* deleteStart(Node* head) {
    if (head == NULL) return NULL;
    Node* current = head;
    head = head -> next;
    free(current);
    return head;
}

// Xat dung ham xoa o vi tri bat ki
Node* deleteAt(Node* head, int index) {
    if (head == NULL || index < 1 || index > getLength(head)) return head;
    if (index == 1 ) {
        head = deleteStart(head);
    }else if (index == getLength(head)) {
        head = deleteEnd(head);
    }else {
        Node* current = head;
        // Lay ra current là node kề với node cần
        for (int i = 1; i < index - 1; i++) {
            current = current -> next;
        }
        Node* deleteNode = current -> next; // Node cần xóa
        Node* nextDelete = deleteNode -> next; // Ngắt ket nối của node kế cận với node can xóa
        // Trỏ lại vị tri cua node can xoa do = node đang sau node can xoa
        current -> next = nextDelete;

        //Giai phong node can xoa
        free(deleteNode);

    }
    return head;
}

// Xay dung ham xoa phan tu co gif tri value
Node* deleteValue(Node* head, int value) {
    if (head == NULL) return head;
    Node* current = head;
    int index = 1;
    while (current != NULL) {
        if (current -> data == value) {
            // Gán lại head và curent, vị trí
            head = deleteAt(head, index);
            current = head;
            index = 1;
            continue; // Tránh bỏ qua -> sót node
        }
        index++;
        current = current -> next;
    }
    return head;
}


int main() {
    Node* head = NULL;
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);
    Node* node4 = createNode(2);
    Node* node5 = createNode(5);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    displayNode(head);
    printf("%d\n", getLength(head));
    head = deleteValue(head, 5);
    printf("\nDS sau khi xoa: \n");
    displayNode(head);

}