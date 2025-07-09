#include<stdio.h>
#include<stdlib.h>

// Khởi tạo cấu trúc cho một phần tử trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
// Xây dựng hàm tạo phần tử mới cho danh sách liên kết
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat them bo nho");
        return NULL;
    }
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

// Khởi tạo cấu trúc cho một ngăn xếp
typedef struct Stack {
    Node* head; // tương tự như top khi triển khai bằng mảng
    // int cap; // khong can thiet, khong co gioi han ve kich thuoc - vi dslk duoc cap phat dong
}Stack;

// Xây dựng hàm khởi tạo ngăn xếp
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> head = NULL;
    return stack;
}
Stack* push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return stack;
    }
    // Push cac node vao cuoi danh sach

    if (stack -> head == NULL) {
        // Vì ban đầu chưa push gì thì stack rỗng
        stack -> head = newNode;
    }else {
        Node* current = stack -> head;
        while (current -> next != NULL) {
            current = current->next;
        }
        newNode -> prev = current;
        current -> next = newNode;
        newNode -> next = NULL;
    }

    return stack;
}
// Xay dung ham lay ra phan tu tren cung
int pop(Stack* stack) {
    if (stack -> head == NULL) {
        printf("Ngan xep rong\n");
        return -1;
    }
    Node* temp = stack -> head;
    if (temp != NULL) {
        int value = temp -> data;
        stack -> head = temp -> next;
        free(temp);
        return value;
    }
}


// Ham lay ra do dai stack
int getLength(Stack* stack) {
    if (stack -> head == NULL) {
        return 0;
    }
    int length = 0;
    Node* current = stack -> head;
    while (current != NULL) {
        length++;
        current =  current -> next;
    }
    return length;
}

// Xay dung ham duyet va in ra cac node của stack
void display(Stack* stack) {
    if (stack != NULL) {
        int len = getLength(stack);
        for (int i=1; i<=len; i++) {
            printf("%d\n", pop(stack));
        }

    }
}

int main() {
    Stack* stack = createStack();
    int max_size;
    printf("Nhap so luong phan tu mang: ");scanf("%d", &max_size);
    printf("Nhap cac phan tu them vao stack: \n");
    for (int i=1; i<=max_size; i++) {
        int t; scanf("%d", &t);
        push(stack, t);
    }
    display(stack);


}
