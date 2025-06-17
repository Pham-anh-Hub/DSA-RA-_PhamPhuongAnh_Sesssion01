#include <stdio.h>
#include <stdlib.h>

int *insertToArr(int *arr, int *size, int number);
int printArr(int *arr, int size);
int *deleteFromArr(int *arr, int *size, int deletePos);



int main(){
    int choice;
    int *numbers = NULL;
    int size = 0;
    do{
        printf("\n*****MENU*****\n");
        printf("1. Them\n");
        printf("2. Hien thi\n");
        printf("3. Xoa\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                numbers = insertToArr(numbers, &size, 1);
                numbers = insertToArr(numbers, &size, 2);
                numbers = insertToArr(numbers, &size, 3);
                numbers = insertToArr(numbers, &size, 4);
                printf("Them vao mang thanh cong !!");
                break;
            case 2:
                printArr(numbers, size);
                break;
            case 3:
                int delIndex;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &delIndex);
                deleteFromArr(numbers, &size, delIndex);
                break;
            case 4:
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while(choice !=4);
    free(numbers);
    return 0;
}

int *insertToArr(int *arr, int *size, int number) {
    // B1. Cấp phát lại bộ nhớ
    arr = (int*)realloc(arr, (*size+1) * sizeof(int));
    //B2. Gán lại giá trị cho phần tử cuối
    arr[*size] = number;
   (*size)++;
    return arr;
}


int printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}

int *deleteFromArr(int *arr, int *size, int deletePos) {
    // Kiem tra vi tri muon xoa
    if (deletePos > *size-1 || deletePos < 0) {
        printf("Vi tri xoa khong hop le");
        return arr;
    }else {
        // Tien hanh xoa
        // Dich cac phan tu phi sau phan tu ve phia truoc 1
        for (int i=deletePos; i<*size - 1; i++) {
            arr[i] = arr[i+1];
        }
        (*size)--;
        // Cap phat lai bo nho cho mang
        arr = (int*)realloc(arr, (*size) * sizeof(int));
        return arr;
    }
}