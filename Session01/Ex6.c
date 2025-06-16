#include <stdio.h>

int main() {
    int n, number, count=0;
    scanf("%d", &n);
    int Arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    printf("Nhap so can tim: ");
    scanf("%d", &number);
    for (int i=0; i<n; i++) {
        if (Arr[i]==number) {
            count++;
        }
    }
    printf("So %d xuat hien : %d lan",number, count);

    // Độ phức tạp về thời gian: O(n);
    // Độ phức tạp về không gian: O(n);
}