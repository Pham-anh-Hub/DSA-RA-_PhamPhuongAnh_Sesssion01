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

void enQueue(Queue *queue, int value) {
    // Khoi tao phan tu moi
    Node * newNode = createNode(value);
    // check cap phat thanh cong hay khong
    if (newNode == NULL) {
        printf("\nQueue is full");
        return;
    }else {
        if (queue -> front == NULL) {
            // Hang doi chua co phan tu nao --> luc nay gan front va rear cung la newNode
            queue -> front = newNode;
            queue -> rear = newNode;
        }else {
            queue -> rear -> next = newNode;
            queue -> rear = newNode;
        }
    }
}

void display(Queue *queue) {
    if (queue -> front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *current = queue -> front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}



int main () {
    Queue* queue = creatQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    display(queue);
    enQueue(queue, 3);
    display(queue);

}