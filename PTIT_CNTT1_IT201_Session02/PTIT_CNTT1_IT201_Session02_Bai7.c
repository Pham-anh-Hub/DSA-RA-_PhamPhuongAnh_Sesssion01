#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int stdSum;
    printf("Nhap tong 2 so can tim"); scanf("%d", &stdSum);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (numbers[i] + numbers[j] == stdSum) {
                printf("%d + %d = %d\n", numbers[i], numbers[j], stdSum);
                return 0;
            }
        }
    }
}