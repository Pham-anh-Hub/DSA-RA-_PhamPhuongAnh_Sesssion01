#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
// Xay dung ham create

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
// Xay dung ham display
void displayList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current != NULL) {
        printf("%d", current -> data);
        if (current -> next != NULL) {
            printf(" <-> ");
        }else {
            printf(" -> ");
        }
        current = current -> next;
    }
    printf("NULL\n");
}

//Xau dung ham getlength
int getLength(Node* head) {
    if (head == NULL) return 0;
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

// Xay dung ham them vao dau
Node* insertHead(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    head -> prev = newNode;
    newNode -> next = head;
    newNode -> prev = NULL;
    head = newNode;
    return head;
}

// Xay dung ham them vao cuoi
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }

    newNode -> prev = current;
    current -> next = newNode;
    newNode -> next = NULL;
    return head;
}

// Xay dung ham them vao vi tri bat ki
Node* insertAt(Node* head, int pos, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    if (pos == 1) {
        return insertHead(head, data);
    }else if (pos == getLength(head)) {
        return insertEnd(head, data);
    }else {
        Node* current = head;
        for (int i = 1; i < pos; i++) {
            current = current -> next;
        }
        // Da lay ra phan tu o vi tri can them
        newNode -> prev = current -> prev;
        newNode -> next = current;
        current -> prev -> next = newNode;
        current -> prev = newNode;
    }
    return head;
}

// Xay dung ham xoa phan tu o dau
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}
// Xay dung ham xoa phan tu cuoi
Node* deleteEnd(Node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    // printf("current -> %d\n", current -> data);
    current = current -> prev;
    current -> next = NULL;
    return head;
}

// xay dung ham xoa o vi tri bat ky

Node* deleteAt(Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        return deleteHead(head);
    }else if (pos == getLength(head)) {
        return deleteEnd(head);
    }else {
        Node* current = head;
        for (int i = 1; i < pos-1; i++) {
            current = current -> next;
        }
        printf("current -> %d\n", current -> data);
        current -> next = current -> next -> next;
        current -> next -> prev = current -> prev;
        return head;
    }
}


int main() {
    Node* head;
    Node* node1 = createNode(2);
    Node* node2 = createNode(2);
    Node* node3 = createNode(8);
    Node* node4 = createNode(4);
    Node* node5 = createNode(7);

    head = node1;
    head -> next = node2;
    node2 -> prev = node1;

    node2 -> next = node3;
    node3 -> prev = node2;

    node3 -> next = node4;
    node4 -> prev = node3;

    node4 -> next = node5;
    node5 -> prev = node4;

}