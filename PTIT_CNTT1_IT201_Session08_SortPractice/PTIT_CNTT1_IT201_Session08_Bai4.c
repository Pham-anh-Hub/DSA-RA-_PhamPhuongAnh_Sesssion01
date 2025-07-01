#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        int min_idx = i;
        for(int j = i+1; j<size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp  = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;


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
    selectionSort(number, n);
    for (int i=0; i<n; i++) {
        printf("%d ", number[i]);
    }

}