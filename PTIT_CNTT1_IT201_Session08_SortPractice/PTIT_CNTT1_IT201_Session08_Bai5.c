#include <stdio.h>

void insertionSort(int arr[], int size) {
    for (int i=0; i<size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu mang: ");scanf("%d", &n);
    int number[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &number[i]);
    }
    printf("Mang sau sap xep: ");
    insertionSort(number, n);
    for (int i=0; i<n; i++) {
        printf("%d ", number[i]);
    }

}