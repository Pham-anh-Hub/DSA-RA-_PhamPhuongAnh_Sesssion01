#include<stdio.h>

void insertionSort(int arr[], int size) {
    for (int i=size-1; i>=0; i++) {
        int temp = arr[size-1];
        int j=i-1;
        while (j >= i && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int size;
    printf("Nhap so luong phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    // Tien hanh sap xep
    // for (int i=0; i<size; i++) {
    //     int temp = number[i];
    //     int j = i - 1;
    //     while (j>=0 && number[j] > temp) {
    //         number[j+1] = number[j];
    //         j--;
    //     }
    //     number[j+1] = temp;
    // }
    insertionSort(number, size);
    printf("Mang sau khi sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }
}