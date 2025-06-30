#include <stdio.h>

int sort(int Arr[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size - i - 1; j++) {
            if (Arr[j] > Arr[j + 1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j+1] = temp;
            }
        }
    }
    return Arr;
}


int main() {
    int size;
    printf("Nhap so phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    int evenArr[50], oddArr[50], evenIndex = 0, oddIndex = 0;
    for (int i=0; i<size; i++) {
        if (number[i] % 2 == 0) {
            evenArr[evenIndex++] = number[i];
        }else {
            oddArr[oddIndex++] = number[i];
        }
    }

    sort(evenArr, evenIndex);
    sort(oddArr, oddIndex);
    int index = 0;
    for (int i=0; i < evenIndex; i++) {
        number[index++] = evenArr[i];
    }
    for (int i=oddIndex - 1; i>=0; i--) {
        number[index++] = oddArr[i];
    }

    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }



}