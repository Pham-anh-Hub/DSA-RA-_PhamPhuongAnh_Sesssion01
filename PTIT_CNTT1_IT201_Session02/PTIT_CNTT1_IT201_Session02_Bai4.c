#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    if (0<n && n<=100) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        int pos, value;
        printf("Nhap vi tri sua: ");scanf("%d", &pos);
        printf("\nNhap gia tri sua: ");scanf("%d", &value);
        numbers[pos] = value;
        for (int i = 0; i < n; i++) {
            printf("%d ", numbers[i]);
        }
    }else {
        printf("Do rong mang khong hop le");
    }
}