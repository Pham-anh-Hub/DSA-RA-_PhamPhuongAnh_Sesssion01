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


// Ham initStack: khoi tao stack.top (Su dung khi stack.top chưa được khởi tạo khi createStack
void initStack(Stack* stack) {
    stack->top = -1;
}

int main() {
    Stack* stack;
    int size_cap = 5;
    stack = createStack(size_cap);
    if (stack -> top) {
        printf("\nKhoi tao thanh cong");
    }else {
        printf("\nKhoi tao khong thanh cong");
    }
}






