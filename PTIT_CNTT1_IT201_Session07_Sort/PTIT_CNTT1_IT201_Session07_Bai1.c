#include <stdio.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }

    for (int i=0; i<size - 1; i++) {
        // j < size - i - 1 : giúp tối ưu thuật toán
        // sau môi vòng lặp, các phần tử lớn nhất đã được đưa về cuối mảng
        for (int j=0; j<size - i-1; j++) {
            if (number[j] > number[j+1]) {
                int temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }
}