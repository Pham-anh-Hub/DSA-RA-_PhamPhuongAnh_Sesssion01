#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so phan tu mang: ");
    scanf("%d", &size);
    if (0<size && size < 1000) {
        int *numbers = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }
        int max = numbers[0];
        for (int i = 0; i < size; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        printf("Max: %d", max);
    }else {
        printf("\nSo luong phan tu khong hop le");
    }
}