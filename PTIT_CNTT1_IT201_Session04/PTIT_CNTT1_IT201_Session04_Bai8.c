#include <stdio.h>

int main() {
    int size;
    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &size);
    int numbers[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    int target, targetIndex[size], count = 0;
    printf("Nhap gia tri phan tu can tim: "); scanf("%d", &target);

    for (int i = 0, j=0; i < size; i++) {
        if (numbers[i] == target) {
            targetIndex[j++] = i;
            count++;
        }
    }
    if (count > 0) {
        printf("Cac vi tri phan tu can tim: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", targetIndex[i]);
        }
    }else {
        printf("Khong tim thay phan tu");
    }
    return 0;

}