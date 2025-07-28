#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
typedef struct {
    int id;
    char customer[30];
    int status;
    char total[30];
}Order;

typedef struct Node{
    Order *order;
    struct Node *next;
}Node;

typedef struct DNode{
    Order *order;
    struct DNode *next;
    struct DNode *prev;
}DNode;


// Tao moi don hang
Order *createOrder() {
    Order *newOrder = (Order*)malloc(sizeof(Order));
    printf("Nhap id don hang: ");
    scanf("%d", &newOrder->id);
    getchar();
    printf("Nhap ten khach hang: ");
    fgets(newOrder->customer, 30, stdin);
    newOrder->customer[strlen(newOrder->customer) - 1] = '\0';
    printf("Nhap trang thai doi hang (1. Da giao 2. Chua giao): ");
    scanf("%d", &newOrder->status);
    getchar();
    printf("Nhap tong tien don hang: ");
    fgets(newOrder->total, 30, stdin);
    newOrder->total[strlen(newOrder->total) - 1] = '\0';
    return newOrder;
}
// Tao moi node dslk don
Node *createNode(Order * order) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->order = order;
    newNode->next = NULL;
    return newNode;
}
// Tao moi node dslk doi
DNode *createDNode(Order *order) {
    DNode *newDNode = (DNode *)malloc(sizeof(DNode));
    newDNode->order = order;
    newDNode->next = NULL;
    newDNode->prev = NULL;
    return newDNode;
}

// Ham them moi dslk don
DNode *push(DNode *dhead, Order *newOrder) {
    DNode *newNode = createNode(newOrder);
    if (newNode == NULL) {
        printf("Danh sach don hang day\n");
        return dhead;
    }
    if (dhead == NULL) {
        dhead = newNode;
        return dhead;
    }
    DNode *current = dhead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
    newNode->prev = current;
    return dhead;
}
// Them vao dslk doi
Node *pushBack(Node *head, DNode *dHead, int ID) {
    DNode *current = dHead;
    while (current != NULL) {
        if (current -> order -> id == ID) {
            Order *targetOrder = current -> order;
            Node *newNode = createNode(targetOrder);
            if (head == NULL) {
                head = newNode;
                return head;
            }
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp -> next;
            }
            temp->next = temp;
            return head;
        }
        current = current -> next;
    }
    printf("Khong tim thay don hang can danh dau!");
    return head;
}

// Ham xoa don hang
DNode *pop(DNode *dhead, int ID) {
    if (dhead == NULL) {
        printf("Danh sach don hang trong\n");
        return dhead;
    }
    if (dhead -> order -> id == ID) {
        DNode *temp = dhead;
        dhead = temp -> next;
        free(temp);
        return dhead;
    }

    DNode *current = dhead;
    while (current->next != NULL) {
        if (current -> next -> order -> id == ID) {
            DNode *tmp= current -> next;
            current -> next = tmp->next;
            free(tmp);
            return dhead;
        }
        current = current->next;
    }
    printf("Khong tim thay don hang can xoa !!");
    return dhead;
}

void updateOrder(DNode *dhead,int ID) {
    if (dhead == NULL) {
        printf("Danh sach don hang trong\n");
        return;
    }
    if (dhead -> order -> id == ID) {
        getchar();
        printf("Nhap Ten khach hang moi: ");
        fgets(dhead -> order -> customer, 30, stdin);
        dhead -> order -> customer[strlen(dhead -> order -> customer) - 1] = '\0';
        printf("Nhap tong tien don hang: ");
        fgets(dhead -> order -> total, 30, stdin);
        dhead -> order -> total[strlen(dhead -> order -> total) - 1] = '\0';
        return;
    }
    DNode *current = dhead;
    while (current != NULL) {
        if (current -> order -> id == ID) {
            getchar();
            printf("Nhap Ten khach hang moi: ");
            fgets(current -> order -> customer, 30, stdin);
            current -> order -> customer[strlen(current -> order -> customer) - 1] = '\0';
            printf("Nhap tong tien don hang: ");
            fgets(current -> order -> total, 30, stdin);
            current -> order -> total[strlen(current -> order -> total) - 1] = '\0';
            return;
        }
        current = current -> next;
    }
    printf("Khong tim thay don hang can cap nhat!!");
}
// Ham chuyen chuoi thanh so
int revert(char *number) {
    int len = strlen(number);
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += (number[i] - '0') * pow(10, len - 1 - i);
    }
    return result;
}

void sortList(DNode *dhead) {
    if (dhead == NULL) {
        printf("Danh sach don hang trong\n");
        return;
    }
    if (dhead -> next == NULL) {
        return;
    }
    DNode *i = dhead;
    while (i -> next != NULL) {
        DNode *j = dhead;
        while (j -> next != NULL) {
            if (revert(j ->order -> total) > revert(j -> next -> order -> total)) {
                Order *temp = j -> order;
                j -> order = j -> next -> order;
                j -> next -> order = temp;
            }
            j = j -> next;
        }
        i = i->next;
    }
    return;
}

void findOrder(DNode *dhead, Node *head) {
    char target[50];
    printf("Nhap ten khach hang don hang can tim: ");
    fgets(target, 50, stdin);
    target[strlen(target) - 1] = '\0';

    DNode *current = dhead;
    while (current != NULL) {
        if (strcmp(current -> order -> customer, target) == 0) {
            printf("Khach hang can tim: ");
            printf("ID: %d\n", current->order -> id);
            printf("Ten khach hang: %s\n", current->order -> customer);
            printf("Trang thai: %s\n", current->order -> status == 1 ? "Da giao" : "Chua giao");
            printf("Tong tien: %s\n", current->order -> total);
            return;
        }
        current = current -> next;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp -> order -> customer, target) == 0) {
            printf("Khach hang can tim: ");
            printf("ID:  %d\n", temp -> order -> id);
            printf("Ten khach hang: %s\n", temp -> order -> customer);
            printf("Trang thai: %s\n", temp->order -> status == 1 ? "Da giao" : "Chua giao");
            printf("Tong tien: %s\n", temp -> order -> total);
            return;
        }
    }
    printf("Khong tim thay khach hang can tim!!");
    return;
}




void display(DNode *dhead) {
    if (dhead == NULL) {
        printf("Danh sach don hang trong\n");
        return;
    }
    Node *current = dhead;
    while (current != NULL) {
        printf("ID: %d\n", current->order -> id);
        printf("Ten khach hang: %s\n", current->order -> customer);
        printf("Trang thai: %s\n", current->order -> status == 1 ? "Da giao" : "Chua giao");
        printf("Tong tien: %s\n", current->order -> total);
        current = current->next;
    }
}


int main() {
    int choice;
    Node *head = NULL;
    DNode *dhead = NULL;
    do {
        printf("\n--------MENU--------\n");
        printf("1. Them moi don hang\n");
        printf("2. Hien thi don hang\n");
        printf("3. Xoa don hang\n");
        printf("4. Cap nhat don hang\n");
        printf("5. Danh dau don hang\n");
        printf("6. Sap xep danh sach don hang\n");
        printf("7. Tim kiem don hang\n");
        printf("8. Thoat\n");
        printf("\tLua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                Order *newOder = createOrder();
                dhead = push(dhead, newOder);
                printf("Them moi don hang thanh cong!!\n");
                break;
            case 2:
                display(dhead);
                break;
            case 3:
                int idDelete;
                printf("Nhap id don hang can xoa: ");
                scanf("%d", &idDelete);
                dhead = pop(dhead, idDelete);
                printf("Xoa don hang thanh cong\n");
                break;
            case 4:
                int idUpdate;
                printf("Nhap id don hang can cap nhat: ");
                scanf("%d", &idUpdate);
                updateOrder(dhead, idUpdate);
                printf("Cap nhat don hang thanh cong!!");
                break;
            case 5:
                int idTick;
                printf("Nhap id don hang da giao: ");
                scanf("%d", &idTick);
                head = pushBack(head, dhead, idTick);
                dhead = pop(dhead, idTick);
                printf("Chuyen giao don hang thanh cong!!");
                break;
            case 6:
                // Sap xep don hang
                sortList(dhead);
                printf("Sap xep danh sach don hang thanh cong!!");
                break;
            case 7:
                findOrder(dhead, head);
                break;
            case 8:
                printf("Thoat chuong trinh !!");
                break;
            default:
                printf("Moi nhap lua chon hop le");
        }
    }while(choice != 8);
    free(head);
    free(dhead);
}