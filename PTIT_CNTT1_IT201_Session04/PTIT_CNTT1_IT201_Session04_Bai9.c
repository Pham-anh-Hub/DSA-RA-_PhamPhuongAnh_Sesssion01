#include<stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[size];
}

int binarySearch(int arr[], int size, int target, int start, int end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    }else if (arr[mid] > target) {
       return binarySearch(arr, size, target, mid + 1, end);
    }else {
       return binarySearch(arr, size, target, start, mid - 1);
    }

}
int main() {
    int size;
    printf("Moi nhap so luong phan tu: "); scanf("%d", &size);
    int numbers[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    bubbleSort(numbers, size);
    int target;
    printf("Nhap gia tri phan tu can tim: ");scanf("%d", &target);

    printf("Vi tri phan tu can tim: %d", binarySearch(numbers, size, target, 0, size - 1));

}