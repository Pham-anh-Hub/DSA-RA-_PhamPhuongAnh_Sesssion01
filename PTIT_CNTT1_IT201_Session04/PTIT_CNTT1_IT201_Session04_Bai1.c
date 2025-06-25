#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: "); scanf("%d", &size);
    int *numbers = (int*)malloc(size * sizeof(int));
    for (int i=0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    int number;
    printf("Nhap phan tu can tim: ");scanf("%d", &number);
    for (int i=0; i < size; i++) {
        if (numbers[i] == number) {
            printf("So can tim nam o vi tri: %d", i);
            return 0;
        }
    }


}
