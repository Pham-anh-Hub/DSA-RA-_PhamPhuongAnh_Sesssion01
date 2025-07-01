#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    int index;
    for (int i=0; i<size; i++) {
        if (arr[i] == target) {
            index = i;
        }
    }
    return index;
}

int main() {
    int n;
    printf("Nhap so luong phan tu mang: ");scanf("%d", &n);
    int number[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &number[i]);
    }
    int target;
    printf("Nhap phan tu can tim: ");scanf("%d", &target);
    printf("Vi tri cua phan tu can tim la: %d", linearSearch(number, n, target) + 1);

}