#include <stdio.h>

int printArray(int arr[], int size, int index) {
    if (index == size) {
        return 0;
    }
    // printf("%d ", arr[index]);
    return arr[index] + printArray(arr, size, index + 1);
}

int main() {
    int size;
    printf("Nhap so luong phan tu mang: "); scanf("%d", &size);
    int number[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &number[i]);
    }
    printf("Tong = %d", printArray(number, size, 0));
}