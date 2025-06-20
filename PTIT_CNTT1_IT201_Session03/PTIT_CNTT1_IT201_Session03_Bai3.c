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
        int evenSum = 0, count = 0;
        for (int i = 0; i < size; i++) {
            if (numbers[i] % 2 == 0) {
                evenSum += numbers[i];
                count++;
            }
        }
        printf("Trung binh cong cac so chan la: %f", (evenSum/count));

    }else {
        printf("So luong phan tu khong hop le");
    }

}