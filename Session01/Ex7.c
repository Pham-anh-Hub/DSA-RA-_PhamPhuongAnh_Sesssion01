#include <stdio.h>
#include <stdbool.h>

bool checkArr() {
    int n; scanf("%d\n", &n);
    int Arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (Arr[i]==Arr[j]) {
                return true;
            }
        }
    }
    return false;
};
// Cách 1
// Độ phức tạp về thời gian: O(n^2)
// Độ phức tạp về không gian: O(n)


bool check_2() {
    int n; scanf("%d\n", &n);
    int Arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    int temp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (Arr[i] < Arr[j]) {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
    for (int i=1; i<n; i++) {
        if (Arr[i]==Arr[i-1]) {
            return true;
        }

    }
    return false;
}
// Cách 2:
// Độ phức tạp thời gian: O(n^2)
// Độ phức tạp không gian: O(n)




int main() {
    if (check_2()) {
        printf("Mang co phan tu trung lap");
    }else {
        printf("Mang khong co phan tu trung lap");
    }


}