#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Stack {
    char arr[100];
    int top;
    int cap;
}Stack;

// Xay ham create
Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    return stack;
}
// Xạy ham pop
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Ngan xep rong");
        return -1;
    }
    int temp = stack->arr[stack->top--];
    return temp;
}
// xay ham push
Stack* push(Stack* stack, int item) {
    if (stack -> top == (stack -> cap) - 1) {
        printf("Ngan xep da day");
        return stack;
    }
    stack->arr[++stack->top] = item;
    return stack;
}


int main() {
    char string[50];
    printf("Nhap vao chuoi: ");fgets(string, 50, stdin);
    string[strlen(string) - 1] = '\0';
    Stack* stack = createStack(strlen(string));
    int res;
    for (int i=0; i<strlen(string); i++) {
        if (isdigit(string[i])) {
            push(stack, string[i] - '0');
        }else {
            if (string[i] == '*' || string[i] == '/' || string[i] == '+' || string[i] == '-') {
                int B = pop(stack);
                int A = pop(stack);

                char c = string[i];
                printf("%d, %d, %c\n", A, B, c);

                switch (c) {
                    case '*':
                        res = A * B;
                        ;break;
                    case '/':
                        res = A / B;
                        ;break;
                    case '+':
                        res = A + B;
                        ;break;
                    case '-':
                        res = A - B;
                        break;
                }

            }
            //printf("%d\n", res);
            //push(stack, res);
        }
    }

    printf("Result: %d", pop(stack));


}


