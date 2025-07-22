#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Queue{
    int **arr;
    int capacity;
    int front;
    int rear;
}Queue;

Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue*)malloc((sizeof(Queue)));
    if (newQueue != NULL) {
        newQueue -> arr = (Node**)malloc(sizeof(Node*) * capacity);
        newQueue -> capacity = capacity;
        newQueue -> front = 0;
        newQueue -> rear = -1;
        return newQueue;
    }

}

void enQueue(Queue *queue, Node *node) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Hang doi day");
        return;
    }
    queue -> arr[++queue -> rear] = node;
}

int isEmpty(Queue *queue) {
   return queue -> front > queue -> rear;
}

Node *deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue -> arr[queue -> front++];
}


Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node *insertTree(Node *root, int data) {
    Node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
        return root;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);

    while (!isEmpty(queue)) {
        // B6 lay node dau ra khoi hang doi va in ra
        Node *node = deQueue(queue);
        if (node -> left == NULL) {
            node -> left = newNode;
            return root;
        }else {
            enQueue(queue, node -> left);
        }
        if (node -> right == NULL) {
            node -> right = newNode;
            return root;
        }else{
            enQueue(queue, node -> right);
        }
    }
}

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    Node *root = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);
    Node *node6 = createNode(6);

    root -> left = node2;
    root -> right = node3;
    node2 -> right = node5;
    node2 -> left = node4;
    node3 -> left = node6;
    printf("\nPreOrder: \n");
    preOrder(root);
    int value;
    printf("Nhap gia tri can them: "); scanf("%d", &value);
    root = insertTree(root, value);
    printf("\nPreOrder: \n");
    preOrder(root);


}