#include <stdio.h>
#include <stdlib.h>

int main() {
    int cols, rows;
    printf("Nhap so hang: ");scanf("%d", &rows);
    printf("Nhap so cot: ");scanf("%d", &cols);
    if (0 < rows && rows < 1000 && 0 < cols && cols < 1000) {
        int numbers[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf("%d", &numbers[i][j]);
            }
        }
        int row, rowCount = 0;
        printf("Nhap hang can tinh tong: ");
        scanf("%d", &row);
        if (0<row && row < rows) {

            for (int i = 0; i < cols; i++) {
                rowCount+=numbers[row-1][i];
                printf("%d ", numbers[row-1][i]);
            }
            printf("\nTong hang %d: %d", row, rowCount);
        }else {
            printf("\nHang can tinh khong ton tai");
        }


    }else{
        printf("\nSo hang hoac so cot khong hop le");
    }
}