#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    // Đếm tần suất xuất hiện
    int checkCnt[n];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (Arr[i] == Arr[j]) {
                count++;
            }
        }
        checkCnt[i] = count;
    }

    // Tìm số lần xuất hiện lớn nhất
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (checkCnt[i] > max) {
            max = checkCnt[i];
        }
    }

    // In phần tử đầu tiên có số lần xuất hiện bằng max
    for (int i = 0; i < n; i++) {
        int isFirst = 1;
        for (int j = 0; j < i; j++) {
            if (Arr[i] == Arr[j]) {
                isFirst = 0;
                break;
            }
        }
        if (isFirst && checkCnt[i] == max) {
            printf("So xuat hien nhieu nhat: %d\n", Arr[i]);
            break;
        }
    }
    return 0;
}
