#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue -> front = 0; //
    queue -> rear = -1;
    queue -> capacity = capacity;
    queue -> data = (int*)malloc(capacity * sizeof(int));
    return queue;
}
// Them phan tu vao dau hang doi
void enQueue(Queue *queue, int value) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> rear++;
    queue -> data[queue -> rear] = value;
}
//xay dung ham xoa va lay ra phan tu cuoi danh sach
void deQueue(Queue *queue) {
    if (queue -> front > queue -> rear) {
        printf("Hang doi trong");
        return;
    }
    int temp = queue -> data[queue -> front + 1];
    queue -> front++;
}
void display(Queue* queue) {
    for (int i = queue -> front; i < queue -> capacity; i++) {
        printf("%d ", queue -> data[i]);
    }
}

int main() {
    int capacity;
    printf ("Nhap so luong hang doi toi da: "); scanf("%d", &capacity);
    Queue *queue = createQueue(capacity);
    if (queue != NULL) {
        printf("Khoi tao hang doi thanh cong");
    }else {
        printf("Khoi tao hang doi chua thanh cong");
    }

}




