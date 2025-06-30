#include <stdio.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    for (int i=0; i<size-1; i++) {
        int min_index = i;
        for (int j=i+1; j<size; j++) {
            if (number[j] < number[min_index]) {
                min_index = j;
            }
        }
        int temp = number[i];
        number[i] = number[min_index];
        number[min_index] = temp;
    }
    printf("Mang sau khi sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }






}