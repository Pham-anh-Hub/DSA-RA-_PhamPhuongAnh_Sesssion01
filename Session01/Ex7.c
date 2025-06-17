#include <stdio.h>
#include <stdbool.h>

bool checkArr(int numbers[], int size) {

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (numbers[i]==numbers[j]) {
                return true;
            }
        }
    }
    return false;
};
// Cách 1 - Vét cạn
// Độ phức tạp về thời gian: O(n^2)
// Độ phức tạp về không gian: O(n)


bool check_2(int numbers[], int size) {
    int temp;
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (numbers[i] < numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    for (int i=1; i<size; i++) {
        if (numbers[i]==numbers[i-1]) {
            return true;
        }

    }
    return false;
}
// Cách 2:
// Độ phức tạp thời gian: O(n^2)
// Độ phức tạp không gian: O(n)


// Cách 3: checkDup bằng mảng phụ
//Tạo mảng phụ kiểm tra phần tử đã được duyệt chưa

int checkDup_2(int numbers[], int size) {
    int checkNumbers[1001];
    // Ứng với từng phần tử đuọc xét thì tăng giá trị

    for (int i=0; i<size; i++) {
        if (checkNumbers[numbers[i]]==1) {
            return 1;
        }else {
            checkNumbers[numbers[i]] = 1;
        }
    }
    return 0;
}


int main() {
    int n; scanf("%d\n", &n);
    int Arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    if (checkDup_2(Arr[n], n)) {
        printf("Mang co phan tu trung lap");
    }else {
        printf("Mang khong co phan tu trung lap");
    }


}