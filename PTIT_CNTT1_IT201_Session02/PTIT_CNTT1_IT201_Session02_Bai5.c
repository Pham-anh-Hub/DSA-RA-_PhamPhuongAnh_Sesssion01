#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    if (0<n && n<=100) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        int delPos;
        printf("Nhap vi tri xoa: ");scanf("%d", &delPos);
        if (delPos>=0 && delPos<n) {
            for (int i = delPos; i < n-1; i++) {
                numbers[i] = numbers[i+1];
            }
            n--;
            // In ra
            for (int i = 0; i < n; i++) {
                printf("%d ", numbers[i]);
            }
        }else {
            printf("Vi tri xoa khong hop le");
        }
    }else {
        printf("Do rong mang khong hop le");
    }
}