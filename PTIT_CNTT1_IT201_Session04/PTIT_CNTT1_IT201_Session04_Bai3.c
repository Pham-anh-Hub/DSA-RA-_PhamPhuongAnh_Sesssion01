#include <stdio.h>
#include<stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: "); scanf("%d", &size);
    int *numbers = (int*)malloc((size) * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    int min = numbers[0], index = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            index = i;
        }
    }
    printf("Gia tri %d - Chi so %d", min, index);
}
