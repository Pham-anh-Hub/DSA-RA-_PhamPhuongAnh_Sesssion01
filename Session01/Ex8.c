#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int Arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    int checkCnt[n];
    for (int i=0; i<n; i++) {
        int count=0;
        for (int j=0; j<n; j++) {
            if (Arr[i] == Arr[j]) {
                count++;
            }
        }
        checkCnt[i] = count;
    }
    int max=0;
    for (int i=0; i<n; i++) {
        if (checkCnt[i] > max) {
            max = checkCnt[i];
        }
    }
    int maxPrintNum[n];
    printf("So xuat hien nhieu nhat: ");
    for (int i=0; i<n; i++) {
        bool printed = false;
        for (int j = 0; j < i; j++) {
            if (Arr[i] == Arr[j]) {
                printed = true;
                break;
            }
        }

        if (!printed && checkCnt[i] == max) {
            printf("%d ", Arr[i]);
            maxPrintNum[i] = Arr[i];
        }
    }
    printf("\nSo xuat hien nhieu nhat dau tien: %d", maxPrintNum[0]);
}

// Độ phức tạp về thời gian O(n^2)
// Độ phức tạp về không gian O(n)