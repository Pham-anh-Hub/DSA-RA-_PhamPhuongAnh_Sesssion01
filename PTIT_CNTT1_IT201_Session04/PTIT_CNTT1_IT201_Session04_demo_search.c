#include <stdio.h>

// int linearSearch(int arr[], int size, int target) {}
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int target) {
    int start = 0, end = size-1;
    while (start <= end) {
        int mid = (start + end) / 2; // hay mid = (size - 1)/2
        if (arr[mid] == target) {
            return mid;
        }else if (arr[mid] < target) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size;
    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &size);
    int numbers[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    int value;
    printf("Nhap phan tu can tim kiem: "); scanf("%d", &value);
    printf("Vi tri phan tu can tim: %d", linearSearch(numbers, size, value));
    printf("\nVi tri: %d, Gia tri: %d", linearSearch(numbers, size, value), numbers[binarySearch(numbers, size, value)]);
}


