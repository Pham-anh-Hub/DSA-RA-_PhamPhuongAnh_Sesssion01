#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

int findMax(Node *root) {
    if (root == NULL) {
        return -99999;
    }
    int maxLeft = findMax(root -> left);
    int maxRight = findMax(root -> right);

    int max = root -> data;
    if (max < maxLeft) {
        max = maxLeft;
    }
    if (max < maxRight) {
        max = maxRight;
    }
    return max;
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
    Node *node7 = createNode(7);
    Node *node5 = createNode(5);
    Node *node6 = createNode(6);

    root -> left = node2;
    root -> right = node3;
    node2 -> right = node5;
    node2 -> left = node7;
    node3 -> left = node6;

    preOrder(root);
    printf("\nMAX: %d ", findMax(root));

}