#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Queue {
    char name[100][30];
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue (int capacity) {
    Queue *newQueue = (Queue*)malloc(sizeof(Queue)*100);
    newQueue -> front = 0;
    newQueue -> rear = -1;
    // newQueue -> name = (char*)malloc(sizeof(char));  // vì đã được cấp phát cứng
    newQueue -> capacity = capacity;
    return newQueue;
}

void enQueue(Queue *queue, char name[30]) {
    // ktra queue full
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> rear++;
    strcpy(queue -> name[queue -> rear], name);
}

int isEmpty(Queue *queue) {
    if (queue -> rear < queue -> front) {
        return 1;
    }
    return 0;
}

char front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return 0;
    }
    return queue -> name[queue -> front++];
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }else {
        for (int i=0; i<=queue -> rear; i++) {
            printf("%d. %s \n",i+1, queue -> name[i]);
        }
    }
}

int main() {
    Queue *queue = createQueue(5);
    enQueue(queue, "Nam");
    enQueue(queue, "Long");
    enQueue(queue, "Mai");
    enQueue(queue, "Quang");
    enQueue(queue, "Minh");

    display(queue);
}