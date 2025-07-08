#include <stdio.h>
#include <stdlib.h>

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
void reverseStack(Stack* stack,int arr[]) {
    Stack* reverStack = createStack(stack -> cap);
    for (int i=0; i<stack -> cap; i++) {
        push(reverStack, pop(stack));
    }
    for (int i=0; i<stack -> cap; i++) {
        printf("%d ", reverStack -> arr[i]);
    }
}


int main() {
    int size_cap = 5;
    Stack* stack = createStack(size_cap);
    for (int i=0; i<size_cap; i++) {
        scanf("%d", &stack->arr[i]);
        stack -> top = i;
    }
    printf("Sau khi reverse: \n");
    reverseStack(stack, stack->arr);
}






