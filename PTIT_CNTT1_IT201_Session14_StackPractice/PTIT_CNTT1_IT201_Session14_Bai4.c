#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Stack {
    Node* head;
}Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack -> head = NULL;
    return newStack;
}

Stack* push (Stack* stack, int value) {
    Node* newNode = createNode(value);
    // Kiem tra cap phat
    if (newNode == NULL) {
        printf("Khong the cap phat them bo nho");
        return NULL;
    }
    // neu ban dau head = NULL thi no chinh la phan tu cuoi
    if (stack -> head == NULL) {
        stack -> head = newNode;
        return stack;
    }else {
        Node* current = stack -> head;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
        return stack;
    }
}

int pop(Stack* stack) {
    if (stack -> head == NULL) {
        printf("Ngan xep rong");
        return -1;
    }
    Node* temp = stack -> head;
    if (temp != NULL) {
        int value = temp -> data;
        stack -> head = temp -> next;
        free(temp);
        return value;
    }
}

void display(Stack* stack) {
    if (stack -> head == NULL) {
        printf("Ngan xep rong");
        return;
    }
    Node* current = stack -> head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}



int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    display(stack);
    pop(stack);
    printf("\nSau khi xoa:\n");
    display(stack);



}