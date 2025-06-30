#include <stdio.h>


void quickSort(int arr[], int start, int end) {

}

int main() {
    int number[] = {4,3,7,1,-5,10,5};
    int j=0;
    int pivot = number[3];
    for (int i = 0; i<7; i++) {

        while (i>j && pivot <= number[i] && pivot >= number[j]) {
            int temp = number[j];
            number[j] = number[i];
            number[i] = temp;
        }
    }
}