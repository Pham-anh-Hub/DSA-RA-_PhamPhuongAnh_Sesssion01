#include <stdio.h>
#include<stdlib.h>
typedef struct Queue {
    int *data;
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue (int capacity) {
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> front = 0;
    newQueue -> rear = -1;
    newQueue -> data = (int*)malloc(sizeof(int)*capacity);
    newQueue -> capacity = capacity;
    return newQueue;
}

void enQueue(Queue *queue, int value) {
    // ktra queue full
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> rear++;
    queue -> data[queue -> rear] = value;
}

int isEmpty(Queue *queue) {
    if (queue -> rear < queue -> front) {
        return 1;
    }
    return 0;
}
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }else {
        for (int i=0; i<=queue -> rear; i++) {
            printf("%d\n", queue -> data[i]);
        }
    }
}


int main() {
    Queue *queue = createQueue(5);
    if (isEmpty(queue)) {
        printf("True");
    }else {
        printf("False");
    }
}