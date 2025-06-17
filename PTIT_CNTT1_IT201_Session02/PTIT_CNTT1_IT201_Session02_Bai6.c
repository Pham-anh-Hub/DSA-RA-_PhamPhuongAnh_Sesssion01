#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    if (0<n && n<=100) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        int addPos, value;
        printf("Nhap vi tri them: ");scanf("%d", &addPos);
        printf("Nhap gia tri them: ");scanf("%d", &value);
        if (addPos>=0 && addPos<=n) {
            for (int i = n; i > addPos; i--) {
                numbers[i] = numbers[i-1];
            }
            numbers[addPos] = value;
            n++;
            numbers = (int *)realloc(numbers, n * sizeof(int));
            // In ra
            for (int i = 0; i < n; i++) {
                printf("%d ", numbers[i]);
            }
        }else {
            printf("Vi tri them khong hop le");
        }
    }else {
        printf("Do rong mang khong hop le");
    }
}