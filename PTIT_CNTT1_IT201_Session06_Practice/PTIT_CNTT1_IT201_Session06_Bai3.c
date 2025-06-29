#include <stdio.h>

int calcTotal(int number) {
    if (number ==0) {
        return 0;
    }
    return number% 10 + calcTotal(number/10);
}

int main() {
    int number;
    printf("Moi nhap so can tinh tong cac chu so: "); scanf("%d", &number);
    printf("Tong = %d",calcTotal(number));
}