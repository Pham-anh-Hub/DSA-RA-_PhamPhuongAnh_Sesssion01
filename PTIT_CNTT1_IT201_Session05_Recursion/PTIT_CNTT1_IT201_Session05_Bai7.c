#include <stdio.h>

int printFibo(int arr[], int n, int cnt) {
    if (cnt == n) {
        return 1;
    }
    if (cnt >=2) {
        arr[cnt] = arr[cnt - 1] + arr[cnt - 2];
    }
    printf("%d ", arr[cnt]);
    printFibo(arr, n, cnt+1);

}

int main() {
    int array[100] = {0, 1};
    int n;
    printf("Nhap so luong so fibonacci can in: ");scanf("%d", &n);
    if (n == 0) {
        printf("So luong nhap khong hop le");
    }else {
        printFibo(array,n, 0);
    }

}