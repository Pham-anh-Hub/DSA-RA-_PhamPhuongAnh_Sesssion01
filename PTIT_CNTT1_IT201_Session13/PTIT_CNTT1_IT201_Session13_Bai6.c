#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack {
    int arr[100];
    int top;
    int cap; // Số lượng phần tử tối đa có trong ngăn xếp
}Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    return stack;
}
int push(Stack* stack, int item) {
    if (stack->top == stack->cap - 1) {
        printf("Stack is full\n");
        return 0;
    }
    stack->arr[++stack->top] = item;
    return stack;
}
// Xay dung ham lap ra phan tu tren dau ngan xep
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("\nStack is empty");
        return 0;
    }
    int temp = stack->arr[stack->top];
    stack -> top--;
    return temp;
}
bool checkPalindrome(char string[]) {
    Stack* stack = createStack(100);
    int k = strlen(string) - 2;
    for (int i=0; i<strlen(string) / 2; i++) {
        if (string[i] != string[k]) {
            return false;
        }
        k--;
    }
    return true;
}
// C2
bool checkPalindrome2(char string[]) {
    Stack* s = createStack(100);
    for (int i=0; i<strlen(string); i++) {
        push(s, string[i]);
    }
    for (int i=0; i<strlen(string); i++) {
        if (string[i] != pop(s)) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Moi nhap vao chuoi can ktra:"); fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (checkPalindrome(str)) {
        printf("true");
    }else {
        printf("false");
    }
}






