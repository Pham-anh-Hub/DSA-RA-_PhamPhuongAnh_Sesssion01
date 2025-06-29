#include <stdio.h>
#include <string.h>

void HaNoi_tower(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("\nDia %d di chuyen tu %c sang %c", n, from, to);
        return;
    }

    HaNoi_tower(n-1, from, temp, to);
    printf("\nDia %d di chuyen tu %c sang %c", n, from, to);
    HaNoi_tower(n-1, temp, to, from);
}

int main() {
    int dish_size;
    printf("Nhap so luong dia: "); scanf("%d", &dish_size);
    HaNoi_tower(dish_size, 'A', 'C', 'B');
}