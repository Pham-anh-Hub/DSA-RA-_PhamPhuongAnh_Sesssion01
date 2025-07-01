#include <stdio.h>

int binarySearch(int arr[], int target, int start, int end) {
    if (start>end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    }else if (arr[mid] < target) {
        binarySearch(arr, target, mid + 1, end);
    }else {
        binarySearch(arr, target, start, mid - 1);
    }

}

int main() {
    int n;
    printf("Nhap so luong phan tu mang: ");scanf("%d", &n);
    int number[n];
    printf("Nhap mang da sap xep: \n");
    for (int i=0; i<n; i++) {
        scanf("%d", &number[i]);
    }
    int target;
    printf("Nhap phan tu can tim: ");scanf("%d", &target);
    printf("Vi tri cua phan tu can tim la: %d", binarySearch(number, target, 0, n-1) + 1);

}