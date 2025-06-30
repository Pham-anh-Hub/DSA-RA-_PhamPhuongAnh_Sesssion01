#include <stdio.h>

int main() {
    int size;
    printf("Nhap so luong phan tu: "); scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    int negArr[50], posArr[50], zeros[50];
    int posIndex = 0, negIndex = 0, zeroIndex = 0;

    for (int i=0; i<size; i++) {
        if (number[i] < 0) {
            negArr[negIndex] = number[i];
            negIndex++;
        }else if (number[i] > 0) {
            posArr[posIndex] = number[i];
            posIndex++;
        }else {
            zeros[zeroIndex] = 0;
            zeroIndex++;
        }
    }
    int index = 0;
    for (int i = negIndex-1; i >= 0; i--) {
        number[index++] = negArr[i];
    }
    for (int i = 0; i < zeroIndex; i++) {
        number[index++] = 0;
    }
    for (int i=posIndex-1; i>=0; i--) {
        number[index++] = posArr[i];
    }
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }



}