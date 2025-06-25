#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu mang: "); scanf("%d", &size);
    int *numbers = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    int target, index = -1;
    printf("Nhap gia tri phan tu can tim: "); scanf("%d", &target);
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            index = i;
        }
    }
    if (index != -1) {
        printf("Chi so phan tu cuoi cung = %d:  %d",target,  index);
    }else {
        printf("Khong tim thay phan tu");
    }

}