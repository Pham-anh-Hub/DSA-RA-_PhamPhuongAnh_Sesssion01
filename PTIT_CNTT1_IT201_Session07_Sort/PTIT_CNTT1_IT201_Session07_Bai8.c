#include<stdio.h>

int main() {
    int rows, cols;
    printf("Nhap so hang: ");scanf("%d", &rows);
    printf("Nhap so cot: "); scanf("%d", &cols);
    int number[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d",&number[i][j]);
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d",number[i][j]);
        }
        printf("\n");
    }
    int arrangeCol;
    printf("Nhap cot can sap xep: "); scanf("%d", &arrangeCol);
    for (int i=0; i<rows; i++) {
        for (int j = 0; j< rows - 1 - i; j++) {
            if (number[j+1][arrangeCol] < number[j][arrangeCol]) {
                int temp = number[j][arrangeCol];
                number[j][arrangeCol] = number[j+1][arrangeCol];
                number[j+1][arrangeCol] = temp;
            }
        }
    }

    printf("Sau khi sap xep: \n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d",number[i][j]);
        }
        printf("\n");
    }
}