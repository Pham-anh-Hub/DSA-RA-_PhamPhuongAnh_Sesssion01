#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i=0; i<size; i++) {
        int min_index = i, swapped = 0;
        for (int j=i+1; j<size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
                swapped = 1;
            }
        }
        if (swapped == 1) {
            int temp  = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }else {
            printf("Khong doi cho\n");
        }
    }
}



int main() {
    int size;
    printf("Nhap so luong phan tu: ");scanf("%d", &size);
    int number[size];
    for (int i=0; i<size; i++) {
        scanf("%d", &number[i]);
    }
    for (int i=0; i<size-1; i++) {
        int min_index = i;
        for (int j=i+1; j<size; j++) {
            if (number[j] < number[min_index]) {
                min_index = j;
            }
        }
        int temp = number[i];
        number[i] = number[min_index];
        number[min_index] = temp;
    }

    printf("Mang sau khi sap xep: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", number[i]);
    }






}