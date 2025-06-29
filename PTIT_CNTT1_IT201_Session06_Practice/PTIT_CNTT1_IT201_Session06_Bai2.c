#include <stdio.h>

int printFibo(int n, int count, int arr[]) {
    if (count == n) {
        return 0;
    }
    if (count >= 2) {
        arr[count] = arr[count - 1] + arr[count - 2];
    }
    printFibo(n, count +1, arr);
    printf("%d ", arr[count]);
}

int main() {
    int fibonacci[100] = {0, 1};
    int size;
    printf("Nhap so luong so fibonacci can in: "); scanf("%d", &size);
    printFibo(size, 0, fibonacci);
}