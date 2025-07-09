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
    Node* temp = stack -> head;
    stack -> head = newNode;
    newNode -> next = temp;
    return stack;
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

// Khởi tạo một ngăn xếp từ hàm đã xây dựng

int main() {
    Stack* stack = createStack();
    printf("length truoc khi khoi tao: %d\n", getLength(stack));
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printf("length sau khi khoi tao: %d", getLength(stack));


}
