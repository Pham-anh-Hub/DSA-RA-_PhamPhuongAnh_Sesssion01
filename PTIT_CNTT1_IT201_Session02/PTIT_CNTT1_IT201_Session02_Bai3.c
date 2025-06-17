#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, findNum; scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("Nhap phan tu can kiem tra: "); scanf("%d", &findNum);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == findNum) {
            count++;
        }
    }
    printf("So %d xuat hien %d lan", findNum, count);
}
