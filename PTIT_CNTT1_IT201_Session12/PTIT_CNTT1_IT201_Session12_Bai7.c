#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
// Ham bieu dien danh sach
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

// Lay duoc length
int getLength(Node* head) {
    if (head == NULL) return 0;
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

// Xay dung ham sap xep danh sach theo selection sort

void arrangeList(Node* head) {
    if (head == NULL) return;
    int length = getLength(head);
    Node* i = head;
    Node* temp = createNode(NULL);
    while (i != NULL) {
        Node* min_node = i;
        Node* j = i -> next;
        while (j != NULL) {
            if (min_node -> data < j -> data) {
                min_node = j;
            }
            j = j -> next;
        }
        if (i != min_node) {
            temp -> data = i -> data;
            i -> data = min_node -> data;
            min_node -> data = temp -> data;
        }
        i = i -> next;
    }
}


int main() {
    Node* head;
    Node* node1 = createNode(6);
    Node* node2 = createNode(2);
    Node* node3 = createNode(8);
    Node* node4 = createNode(3);
    Node* node5 = createNode(7);
    Node* node6 = createNode(9);

    head = node1;
    head -> next = node2;
    node2 -> prev = node1;

    node2 -> next = node3;
    node3 -> prev = node2;

    node3 -> next = node4;
    node4 -> prev = node3;

    node4 -> next = node5;
    node5 -> prev = node4;

    node5 -> next = node6;
    node6 -> prev = node5;

    displayList(head);
    printf("\Sau khi sap xep: \n");
    arrangeList(head);
    displayList(head);
}




