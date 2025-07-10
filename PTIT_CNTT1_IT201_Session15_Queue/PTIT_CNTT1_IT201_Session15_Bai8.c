#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Xay dung doi tuong khach hang
typedef struct client {
    char name[30];
    int age;
}Client;

// Xay dung cau truc hang doi
typedef struct Queue {
    Client *client;
    int front;
    int rear;
    int capacity;
}Queue;

// Xay ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    queue -> client = (Client*)malloc(sizeof(Client)*100);
    return queue;
}
int isEmpty(Queue *queue) {
    if (queue -> rear < queue -> front) {
        return 1;
    }
    return 0;
}
// Xay dung ham them moi vao hang doi
void enQueue(Queue *queue, char name[30], int age) {
    // Kiểm tra hàng đợi đã đầy chưa
    if (queue -> rear == queue -> capacity - 1) {
        printf("Hang doi rong");
        return;
    }
    queue -> rear++;
    queue -> client[queue -> rear].age = age;
    strcpy(queue -> client[queue -> rear].name, name);

}
// Xay dung ham display
void display(Queue *queue) {
    // check hang doi rong
    if (isEmpty(queue)) {
        printf("Hang doi rong");
        return;
    }
    for (int i=0; i <= queue -> rear; i++) {
        printf(" %s - %d,", queue ->client[i].name, queue -> client[i].age);
    }
}


int main() {
    Queue *queueOlder = createQueue(100);
    Queue *queueNormal = createQueue(100);
    //Them cac doi tuong nguoi dung vao mang
    enQueue(queueOlder, "abc", 65);
    enQueue(queueOlder, "ghi", 70);
    enQueue(queueNormal, "cde", 55);
    enQueue(queueNormal, "efg", 45);
    printf("Khach hang >= 60 tuoi: ");
    display(queueOlder);
    printf("\nKhach hang < 60 tuoi: ");
    display(queueNormal);
}

