#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue(int capacity) {
    // Cap phat bo nho
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> data = (int*)malloc(capacity * sizeof(int));
    newQueue -> front = 0;
    newQueue -> rear = -1;
    newQueue -> capacity = capacity;
    return newQueue;
}

// Xay dung ham them vao hang doi
void *enQueue(Queue *queue, int value) {
    if (queue -> rear > queue -> capacity - 1) {
        printf ("Hang doi da day\n");
        return;
    }
    queue -> rear++;
    queue -> data[queue -> rear] = value;
}

void display(Queue *queue) {
    if (queue -> rear < queue ->front) {
        printf("Hang doi rong\n");
        return;
    }
    for (int i=0; i<=queue->rear; i++) {
        printf("%d ", queue -> data[i]);
    }
    printf("\nfront: %d", queue -> front);
    printf("\nrear: %d", queue -> rear);
    printf("\ncapacity: %d", queue -> capacity);
}


int main() {
    // Khoi tao Queue moi
    int capacity;
    printf("Nhap so luong hang doi toi da: ");scanf("%d", &capacity);
    Queue *queue = createQueue(capacity);
    display(queue);
    printf("\nSau khi them: ");
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    display(queue);
}



