#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu mang: "); scanf("%d", &size);
    if (0<size && size < 1000) {
        int *numbers = (int*)malloc((size) * sizeof(int));
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }
        int k = size - 1;
        for (int i = 0; i < k; i++) {
            if (numbers[i] == numbers[k]) {
                printf("Cap doi xung: (%d,%d)\n", numbers[i], numbers[k]);
            }
            k--;
        }
    }else {
        printf("So luong phan tu mabg khong hop le");
    }
}