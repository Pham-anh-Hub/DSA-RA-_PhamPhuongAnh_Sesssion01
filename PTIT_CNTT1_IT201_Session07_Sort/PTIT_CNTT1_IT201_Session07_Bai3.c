#include<stdio.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    // Tien hanh sap xep
    for (int i=0; i<size; i++) {
        int temp = number[i];
        int j = i - 1;
        while (j>=0 && number[j] > temp) {
            number[j+1] = number[j];
            j--;
        }
        number[j+1] = temp;
    }
    printf("Mang sau khi sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }
}