#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int number;
    printf("Nhap vao so can tinh giai thua: "); scanf("%d", &number);
    printf("Giai thua cua %d = %d",number, factorial(number));
}