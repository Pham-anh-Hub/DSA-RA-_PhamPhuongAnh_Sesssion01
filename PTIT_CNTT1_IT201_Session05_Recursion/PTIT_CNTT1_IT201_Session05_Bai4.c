#include <stdio.h>

int calculate(int x, int y) {
    if (x > y) {
        return 0;
    }
    return x + calculate(x + 1, y);
}

int main() {
    int a, b;
    printf("Nhap a: "); scanf("%d", &a);
    printf("Nhap b: "); scanf("%d", &b);
    printf("Tong = %d ",calculate(a, b));
}