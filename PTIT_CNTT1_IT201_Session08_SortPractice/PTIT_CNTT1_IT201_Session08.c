#include <stdio.h>


// XAy dung ham phan vung

int partition(int arr[], int left, int right) {
    // B1. Chon phan tu cuoi cung lam pivot
        int pivot = arr[right];
    // Khoi tao bien luu tru vi tri can chen pivot = left - 1 (chi khoi tao)
    int i = left - 1;
    // Su dung vong lap de tim vi tri can chen pivot
    for (int j=left; j<right; j++) {
        if (arr[j] <= pivot ) {
            i++;
            // Doi cho phan tu < pivot voi vi tri can chen
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
    }
    // Doi cho pivot voi phan tu nam o vi tri can chen
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;


    return i+1;

}



// Xay dung ham de quy su dung thuat toan quick sort
void quickSort(int arr[], int left, int right) {
    // Dieu kien dung khi co it hon 1 phan tu
    if (left < right) { // luon dung

        // B2. Thuc hien phan vung mang can sap xep
        int pivotPos = partition(arr, left, right);

        //  B3. Goi lai ham voi cac phan ben trai va ben phai
        quickSort(arr, left, pivotPos - 1);
        quickSort(arr, pivotPos + 1, right);
    }
}

int main() {
    int number[] = {1,6,3,7,9,2,5};
    // int size = sizeof(number) / sizeof(number[0]);
    quickSort(number, 0, 6);
    for(int i=0; i<7; i++) {
        printf("%d ", number[i]);
    }
}