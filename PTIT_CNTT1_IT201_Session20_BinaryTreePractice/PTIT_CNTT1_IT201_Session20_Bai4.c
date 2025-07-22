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

int checkLeaf(Node *node) {
    if (node -> left == NULL && node -> right == NULL) {
        return 1;
    }
    return 0;
}

int countLeaves(Node *root, int cnt) {
    if (root == NULL) {
        return cnt;
    }
    if (checkLeaf(root)) {
       cnt++;
    }
    cnt = countLeaves(root->left, cnt);
    cnt = countLeaves(root -> right, cnt);
    return cnt;
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

    preOrder(root);
    printf("\n so la: %d ", countLeaves(root, 0));

}