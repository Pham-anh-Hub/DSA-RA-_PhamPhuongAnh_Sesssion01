#include <stdio.h>
#include <stdlib.h>

int binarySearch(int size, int arr[], int target) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        }else if (arr[mid] < target) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

}

int main() {
    int size;
    printf("Nhap so luong phan tu mang: "); scanf("%d", &size);
    int *numbers = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    // Tien hanh sap xep
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    int targetNum;
    printf("\nNhap phan tu can tim:  "); scanf("%d", &targetNum);
    int index = binarySearch(size, numbers, targetNum);
    if (0<=index && index<size) {
        printf("Phan tu co trong mang");
    }else {
        printf("Phan tu khong co trong mang");
    }

}