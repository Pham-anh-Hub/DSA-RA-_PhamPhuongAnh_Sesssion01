#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Operation {
    char url[50];
    char timeStamp[50];
}Operation;

typedef struct Stack{
    Operation **data;
    int top;
    int size;
}Stack;

// Lấy thời điểm hiện tại
void getCurrentDateTime(char *buffer, int size) {
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer, size, "%d/%m/%Y %H:%M", timeinfo); // Format dd/mm/yyyy HH:MM
}

// Tao moi tien trinh
Operation *createOperation() {
    Operation *newOperation = (Operation *)malloc(sizeof(Operation));
    printf("Nhap url: ");
    fgets(newOperation->url, 50, stdin);
    newOperation -> url[strlen(newOperation->url) - 1] = '\0';
    // Lay thoi ddiem hien tai
    getCurrentDateTime(newOperation->timeStamp, 50);
    return newOperation;
}

// tao moi stack
Stack *createStack(int capacity) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> data = (Operation **)malloc(sizeof(Operation*) * 100);
    newStack->top = -1;
    newStack->size = capacity;
    return newStack;
}

// Them moi vao stack;
Stack *pushStack(Stack *stack, Operation *newOperation) {
    if(stack->top == stack->size - 1) {
        printf("Danh sach lich su danh sach day!!");
        return stack;
    }
    stack -> data[++stack -> top] = newOperation;
    return stack;
}

Operation *popStack(Stack *stack) {
    Operation *topOperation = stack -> data[stack -> top];
    stack -> top--;
    return topOperation;
}

void printTopOperation(Stack *stack) {
    Operation *topOperation = stack -> data[stack -> top];
    printf("Dia chi: %s\n", topOperation -> url);
    printf("Thoi diem: %s\n", topOperation -> timeStamp);
}




int main() {
    int choice;
    Stack *backStack = createStack(100); // trang web da truy cap
    Stack *forwardStack = createStack(100); // trang web vua truy cap lai
    do {
        printf("\n-------WEB HISTORY-------\n");
        printf("1. Truy cap trang web moi\n");
        printf("2. Quay lai trang web truoc\n");
        printf("3. Di den trang wweb sau\n");
        printf("4. In dia chi trang web hien tai\n");
        printf("5. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                Operation *newOperation = createOperation();
                // Them vao stack Back
                backStack = pushStack(backStack, newOperation);
                break;
            case 2:
                // Lay trang web moi nhat ra khoi lich su truy cap
                if (backStack->top == -1) {
                    printf("Chua co trang web nao duoc truy cap!");
                }else {
                    Operation *currentWeb = popStack(backStack);
                    // Dua trang web do vao forwardStack
                    forwardStack = pushStack(forwardStack, currentWeb);
                }
                break;
            case 3:
                if (forwardStack->top == -1) {
                    printf("Chua co trang web nao duoc truy cap truoc do !\n");
                }else {
                    // Lay trang web tren cung trong forward Stack
                    Operation *forwardWeb = popStack(forwardStack);
                    // Dua vao lai backStack
                    backStack = pushStack(backStack, forwardWeb);
                }
                break;
            case 4:
                if (backStack->top != -1) {
                    printTopOperation(backStack);
                }else {
                    printf("Lich su truy cap trong\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Lua chon khong hop le");
        }
    }while(choice != 5);
    free(backStack);
    free(forwardStack);
}