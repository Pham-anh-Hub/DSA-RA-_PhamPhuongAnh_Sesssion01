#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 200

typedef struct Request {
    int id;
    char issue[50];
    int priority;
}Request;

// Tao moi yeu cau
Request *createRequest() {
    Request *newRequest = (Request *)malloc(sizeof(Request));
    printf("ID: ");
    scanf("%d", &newRequest->id);
    getchar();
    printf("ISSUE: ");
    fgets(newRequest->issue, 50, stdin);
    newRequest->issue[strlen(newRequest->issue)-1] = '\0';
    printf("PRIORITY (1. high, 2. low):  ");
    scanf("%d", &newRequest->priority);
    return newRequest;
}

typedef struct Queue {
    Request **request;
    int front;
    int rear;
    int size;
}Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue -> request = (Request **)malloc(size * sizeof(Request *));
    queue -> front = 0;
    queue -> rear = -1;
    queue -> size = size;
    return queue;
}
void enqueue(Queue *queue, Request *request) {
    if (queue -> rear == queue -> size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> rear++;
    queue -> request[queue -> rear] = request;

}

void *dequeue(Queue *queue) {
    if (queue -> front > queue -> rear) {
        printf("Queue is empty\n");
        return;
    };
    queue -> front++;
    printf("Yeu cau da duoc xu ly");
    return;
}

Request *frontRequest(Queue *queue) {
    if (queue -> front > queue -> rear) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue -> request[queue -> front];
}

void printQueue(Queue *queue) {
    if (queue -> front > queue -> rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue -> front; i <= queue -> rear; i++) {
        printf("\tID: %d\n", queue -> request[i]->id);
        printf("ISSUE: %s\n", queue -> request[i]-> issue);
        printf("PRIORITY: %d\n", queue -> request[i]->priority);
    }
}

int main() {
    Queue *highQueue = createQueue(MAX);
    Queue *lowQueue = createQueue(MAX);
    int choice;
    do {
        printf("\n---------- REQUEST SYSTEM---------");
        printf("\n1. REQUEST");
        printf("\n2. HANDLE REQUEST");
        printf("\n3. TOP REQUEST");
        printf("\n4. ALL REQUEST");
        printf("\n5. EXIT");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                Request *request = createRequest();
                if (request->priority == 1) {
                    enqueue(highQueue, request);
                }else {
                    enqueue(lowQueue, request);
                }

                break;
            case 3:
                if (highQueue -> rear > 0) {
                    //highQueue khong trong
                    Request *request = frontRequest(highQueue);
                    printf("Yeu cau can xu ly: \n");
                    printf("\tID: %d\n", request->id);
                    printf("\tISSUE: %s\n", request->issue);
                    printf("\tPRIORITY: %d\n", request->priority);
                }else {
                    // highQueue trong
                    Request *request = frontRequest(lowQueue);
                    printf("Yeu cau can xu ly: \n");
                    printf("\tID: %d\n", request->id);
                    printf("\tISSUE: %s\n", request->issue);
                    printf("\tPRIORITY: %d\n", request->priority);
                }
                break;
            case 2:
                if (highQueue -> rear > 0) {
                    dequeue(highQueue);
                }else {
                    dequeue(lowQueue);
                }
                break;
            case 4:
                printf("Do uu tien cao: \n");
                printQueue(highQueue);
                printf("Do uu tien thap: \n");
                printQueue(lowQueue);
                break;
            case 5:
                break;
        }
    }while (choice != 5);
    free(highQueue);
    free(lowQueue);

}

