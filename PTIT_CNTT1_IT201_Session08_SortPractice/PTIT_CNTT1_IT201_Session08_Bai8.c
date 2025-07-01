#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int binarySearch(int arr[], int target, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    }else if (arr[mid] > target) {
        return binarySearch(arr, target, start, mid-1);
    }else {
        return binarySearch(arr, target, mid+1, end);
    }
}

int linearSearch(int arr[], int size, int target, int index) {
    if (index == size) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    linearSearch(arr, size, target, index+1);
}

int main() {
    int size;
    printf("Nhap so luong phan tu: \n"); scanf("%d", &size);
    int number[size];
    printf("\nNhap cac phan tu: ");
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    insertionSort(number, size);
    printf("\nMang sau sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }
    int target;
    printf("\nNhap phan tu can tim: "); scanf("%d", &target);
    printf("\nVi tri phan tu can tim bang linear: %d", linearSearch(number, size, target, 0));
    printf("\nVi tri phan tu sap xep bang binary: %d", binarySearch(number, target, 0, size-1));
}