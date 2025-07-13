#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* front;
    Node* rear;
}Queue;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}
Queue* creatQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int main () {
    Queue* queue = creatQueue();
    if (queue != NULL) {
        printf("\nKhoi tao hang doi thanh cong");
    }else{
        printf("\nKhoi tao khong thanh cong");
    }
}