#include <stdio.h>

int findMaxMin(int arr[], int i, int max, int min) {
    if (i > 4) {
        printf("Max: %d, Min: %d", max, min);
        return 0;
    }
    if (max < arr[i]) {
        max = arr[i];
    }
    if (min > arr[i]) {
        min = arr[i];
    }
    findMaxMin(arr, i+1, max, min);
}

int main() {
    int number[5] = {3,2,4,1,5};
    int max = number[0];
    int min = number[0];
    findMaxMin(number, 0, max, min);
}