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
    printf("Khoi tao Stack thanh cong");
    return stack;
}


// Khởi tạo một ngăn xếp từ hàm đã xây dựng

int main() {
    Stack* stack = createStack();
}

// Xay dung cac ham thao tac voi ngan xep
Stack* push(Stack* stack,int value) {
    // Them 1 phan tu moi vao stack <=> them node vao danh sach lien ket
    Node* newNode = createNode(value);
    Node* temp = stack -> head;
    stack -> head = newNode;
    newNode -> next = temp;
    printf("Push thanh cong");
    return stack;
}
// Xay dung ham lay ra phan tu tren dinh stack
int pop(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is empty");
        return -1;
    }
    Node* temp = stack -> head;

    if (temp != NULL) {
        int value = temp -> data;
        // Xoa phan tu dau tien
        stack -> head = temp -> next;
        free(temp);
        return value;
    }else {
        printf("head = NULL");
        return 0;
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