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
// Xay dung ham lap ra phan tu dau tien cua ngan xep
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("\nNo element in stack");
        return 0;
    }
    int temp = stack->top;
    stack -> top--;
    return temp;
}


// Ham initStack: khoi tao stack -> sử dụng khi chưa khởi tạo top khi createStack
void initStack(Stack* stack) {
    stack->top = -1;
    printf("Khoi tao thanh cong top %d",stack -> top);
}

int main() {
    Stack* stack;
    int size_cap = 5;
    stack = createStack(size_cap);
    for (int i=0; i<size_cap; i++) {
        scanf("%d", &stack->arr[i]);
        stack -> top = stack->arr[i];
    }
    printf("\ntop: %d", stack -> top );
    printf("\ncap: %d", stack -> cap );
    printf("\n%d", pop(stack));


}






