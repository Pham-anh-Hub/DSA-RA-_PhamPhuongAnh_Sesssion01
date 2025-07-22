#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Queue {
    int **arr;
    int capacity;
    int front;
    int rear;
}Queue;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode ->left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Queue *createQueue(int capacity){
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> arr = (Node**)malloc(sizeof(Node*) * capacity);
    newQueue -> front = 0;
    newQueue -> rear = -1;
    return newQueue;
}

void enQueue(Queue *queue, Node *data) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Hang doi day!!");
        return;
    }
    queue -> arr[++queue -> rear] = data;
}
Node *deQueue(Queue *queue) {
    return queue -> arr[queue -> front++];
}

int isEmpty(Queue *queue) {
    return queue -> front > queue -> rear;
}

int sizeQueue(Queue *queue) {
    int count = 0;
    int temp = queue -> front;
    while (temp <= queue -> rear) {
        temp++;
        count++;
    }
    return count;
}

int levelInTree(Node *root, int target) {
        if (root == NULL) {
            return 0;
        }
        Queue *queue = createQueue(100);
        int level = 0;
        enQueue(queue, root);
        while (!isEmpty(queue)) {
            int size = sizeQueue(queue);
            // Vong lap duyet cac node o cung 1 tang
            for (int i=0; i<size; i++) {
               Node *node = deQueue(queue);
                if (node -> data == target) {
                    free(queue);
                    return level;
                }
                if (node -> left != NULL) {
                    enQueue(queue, node -> left);
                }
                if (node -> right != NULL) {
                    enQueue(queue, node -> right);
                }
            }
            level++;
        }
    free(queue);
    return -1;
}

int main(void) {
    Node *root = NULL;
    root = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);
    root -> left = node3;
    root -> right = node4;
    node3 -> left = node5;
    int target;
    printf("Nhap gia tri can tim: "); scanf("%d", &target);
    printf("Level: %d", levelInTree(root, target));
}