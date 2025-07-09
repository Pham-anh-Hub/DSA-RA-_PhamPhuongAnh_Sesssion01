#include<stdio.h>
#include<stdlib.h>
#define MAX = 100;

// Xay dung cau truc du lieu
typedef struct Stack {
    int arr[100];
    int top;
    int cap;
}Stack;

// Xay dung ham tao moi stack;
Stack* createStack(int size) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack)); // Cap phat dong bo nho cho ngan xep moi
    newStack->top = -1;
    newStack->cap = size;
    return newStack;
}

// Xay dung ham day phan tu vao ngan xep
Stack* push(Stack* stack, int data) {
    if (stack -> top == stack -> cap -1) {
        printf("Ngan xep da day");
        return stack;
    }
    stack -> arr[++stack -> top] = data;
    return stack;
}


// Xay dung ham lay ra phantu tren dinh ngan xep
int pop(Stack* stack) {
    if (stack -> top == -1) {
        printf("Ngan xep rong");
    }
    int temp = stack -> arr[stack -> top--];
    return temp;
}



int main() {
    int size;
    printf("Nhap so luong phan tu toi da cua ngan xep: "); scanf("%d", &size);
    Stack* stack = createStack(5);
    printf("Nhap cac phan tu vao ngan xep: ");
    for (int i=0; i < size; i++) {
        int t;
        scanf("%d", &t);
        push(stack, t);
    }

    for (int i=0; i<size; i++) {
        printf("%d ", pop(stack));
    }


}
