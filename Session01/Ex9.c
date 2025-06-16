#include <stdio.h>

void printMatrix(int a, int Arr[a][a]) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            printf("%d ", Arr[i][j]);
        }
        printf("\n");
    }
}

void printMainDigonal(int a, int Arr[a][a]) {
    for (int i=0; i<a; i++) {
        for (int j=0; j<a; j++) {
            if (i==j) {
                printf("%d ", Arr[i][j]);
            }else {
                printf("\t");
            }
        }
        printf("\n");
    }
}


int main() {
    int Matrix[5][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    printMatrix(5,Matrix);
    printf("\n");
    printMainDigonal(5,Matrix);

}

// Thay biến a trong các hàm = n
// Hai hàm có độ phức
// Độ phức tạp về thời gian: O(n^2)
// Độ phức tạp về không gian: O(1) - mảng dữ liệu 2 chiều được khởi tạo sẵn