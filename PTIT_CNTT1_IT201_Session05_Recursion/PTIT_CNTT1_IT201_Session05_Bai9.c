#include <stdio.h>

int paths(int row, int col, int blockedCol, int blockedRow) {
    // Khi  đến điểm bị chặn
    if (row == blockedRow && col == blockedCol) {
        return 0;
    }
    // Khi vuot bien
    if (row < 0 || col < 0) {
        return 0;
    }
    // đến điểm cuối
    if (row == 0 && col == 0) {
        return 1;
    }


    return paths( row-1, col, blockedCol, blockedRow) + paths(row, col-1, blockedCol, blockedRow);
}

int main() {
    int i, j, row, col,blockedRow, blockedCol;

    printf("Moi nhap so hang: ");scanf("%d", &row);
    printf("Moi nhap so cot: ");scanf("%d", &col);
    printf("Moi nhap hang bi chan: ");scanf("%d", &blockedRow);
    printf("Moi nhap cot bi chan: ");scanf("%d", &blockedCol);

   printf("%d", paths(row-1,col-1, blockedCol, blockedRow)) ;
}