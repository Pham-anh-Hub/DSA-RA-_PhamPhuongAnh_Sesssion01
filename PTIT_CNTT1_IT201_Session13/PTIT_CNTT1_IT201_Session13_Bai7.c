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
        // printf("\nStack is empty");
        return 0;
    }
    int temp = stack->arr[stack->top];
    stack -> top--;
    return temp;
}
bool check(char in, char out) {
    if (in == '(' && out == ')' || in == '[' && out == ']' || in == '{' && out == '}') {
        return true;
    }else {
        return false;
    }
}


int main() {
    char str[100];
    printf("Moi nhap vao chuoi can ktra:");
    fgets(str, sizeof(str), stdin);str[strlen(str)-1] = '\0';
    int len = strlen(str);
    Stack* m_stack = createStack(len);
    int temp = 1;
    for (int i=0; i<len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(m_stack, str[i]);
        }else {
            if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
                // printf("%c - %c\n",pop(m_stack), str[i]);
                if (!check(pop(m_stack), str[i])) {
                    temp = 0;
                    break;
                }
            }
        }
    }
    if (m_stack -> top != -1) {
        temp = 0;
    }

    if (temp) {
        printf("true");
    }else {
        printf("false");
    }

}






