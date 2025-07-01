#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int swapped = 0;
    for (int i=0; i<size; i++) {
        for(int j = 0; j<size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp  = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
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
    bubbleSort(number, n);
    for (int i=0; i<n; i++) {
        printf("%d ", number[i]);
    }

}