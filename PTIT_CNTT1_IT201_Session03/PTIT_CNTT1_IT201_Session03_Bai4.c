#include <stdio.h>
#include <stdlib.h>

void findMaxMin(int cols, int rows, int numbers[cols][rows]){
    int max = numbers[0][0];
    int min = numbers[0][0];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (numbers[i][j] > max) {
                max = numbers[i][j];
            }else if (numbers[i][j] < min) {
                min = numbers[i][j];
            }
        }
    }

    printf("Max = %d, Min = %d", max, min);

}
int main() {
    int cols, rows;
    printf("Nhap so hang: ");
    scanf("%d", &cols);
    printf("Nhap so cot: ");
    scanf("%d", &rows);
    int numbers[cols][rows];
    if (0<cols && cols < 1000 && 0<rows && rows < 1000) {
        for (int i=0; i<cols; i++) {
            for (int j=0; j<rows; j++) {
                scanf("%d", &numbers[i][j]);
            }
        }
        findMaxMin(cols, rows, numbers);
    }else {
        printf("\nSo luong phan tu mang khong hop le");
    }
}