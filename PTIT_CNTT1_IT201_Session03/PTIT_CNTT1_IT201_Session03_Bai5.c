#include <stdio.h>
#include <stdlib.h>

void calDiagonals(int cols, int rows, int numbers[cols][rows]) {
    int mainDiagonals=0, scndDiagonals=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                // Đường chéo chính
                mainDiagonals+=numbers[i][j];
                printf("%d ",numbers[i][j] );
            }
            if (i + j == cols - 1) {
                scndDiagonals+=numbers[i][j];
            }
        }
    }
    if (cols == rows) {
        printf("\nTong duong cheo chinh: %d", mainDiagonals);
        printf("\nTong duong cheo phu: %d", scndDiagonals);
    }else {
        printf("\nKhong ton tai duong cheo chinh");
        printf("\nKhong ton tai duong cheo phu");
    }


}

int main() {
    int cols, rows;
    printf("Nhap so hang: ");scanf("%d", &rows);
    printf("Nhap so cot: ");scanf("%d", &cols);
    if (cols<0 || cols > 1000 || rows<0 || cols>1000 ) {
        printf("So luong phan tu khong hop le");
    }else {
        int numbers[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf("%d", &numbers[i][j]);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", numbers[i][j]);
            }
            printf("\n");
        }

        calDiagonals(cols, rows, numbers);
    }
}