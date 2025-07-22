#include<stdio.h>
#include <stdlib.h>

// khoi tao 1 phan tu cho cay
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// Xay dung cau truc Queue -> su dung BFS
typedef struct Queue {
    Node **arr;
    int front;
    int rear;
    int capacity;
}Queue;

// Tao queue
Queue *createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue -> arr = (Node**)malloc(sizeof(Node*)*capacity);
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    return queue;
}

Queue *enQueue(Queue *queue, Node *newNode) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Hang doi day");
        return queue;
    }
    queue -> arr[++queue -> rear] = newNode;
    return queue;
}
int isEmpty(Queue *queue) {
   return queue -> front > queue -> rear;
}
// Lay phan tu ra khoi queue
Node *deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue -> arr[queue ->front++];
}

// Xoa node voi BFS
Node *removeNode(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    Queue *queue = createQueue(100);
    enQueue(queue,root);
    Node *target = NULL, *lastNode = NULL, *lastParent = NULL;
    while (!isEmpty(queue)) {
        Node *node = deQueue(queue);
        //  B5.1 kiem tra node do co gia tri bang gtri can xoa hay khong
        if (node -> data == data) target = node;
            // B6. Kiem tra con ben trai
        if (node -> left != NULL) {
            enQueue(queue, node -> left);
            lastParent = node;
            lastNode = node -> left;
        }
        // B7. Kiem tra con ben phai
        if (node -> right != NULL) {
            enQueue(queue, node -> right);
            lastParent = node;
            lastNode = node -> right;
        }
    }
    if (target == NULL) {
        return root;
    }
    if (lastNode != NULL){
        target -> data = lastNode -> data;
        if (lastParent -> left == lastNode) {
            lastParent -> left = NULL;
        }else {
            lastParent -> right = NULL;
        }
        free(lastNode);
    }else {
        free(root);
        return NULL;
    }
    return root;
}

// Tao Node
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
// preorder() - duyet truoc
void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}



int main() {
    Node *root = NULL;
    root = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);
    Node *node6 = createNode(6);

    root -> left = node2;
    root -> right = node3;
    node2 -> left = node4;
    node3 -> left = node5;
    printf("preOrder: \n");
    preOrder(root);
    int target;
    printf("\nNhap gia tri can xoa: ");scanf("%d", &target);
    root = removeNode(root, target);
    printf("preOrder: \n");
    preOrder(root);

}
