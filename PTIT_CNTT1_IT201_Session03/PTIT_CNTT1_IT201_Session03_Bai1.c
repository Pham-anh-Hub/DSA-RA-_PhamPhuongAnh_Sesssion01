#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu (0, 1000): ");
    scanf("%d", &n);
    if (0<n && n< 1000) {
        int *numbers = (int*)malloc((n+1) * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", numbers[i]);
        }
    free(numbers);

    }else {
        printf("So luong phan tu khong hop le");
    }
}