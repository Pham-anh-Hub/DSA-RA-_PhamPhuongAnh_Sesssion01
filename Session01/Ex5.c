#include <stdio.h>

int main(){
    // Bubble sort
    int n;
    printf("Nhap so n: ");
    scanf("%d\n", &n);
    int Arr[1000];
    for (int i=0; i<n; i++) {
        scanf("%d", &Arr[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            int temp;
            if (Arr[i]<Arr[j]) {
                temp = Arr[j];
                Arr[j] = Arr[i];
                Arr[i] = temp;
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d ", Arr[i]);
    }

    return 0;
}
// Độ phức tạp về thời gian: O(n2)
// Độ phức tạp về không gian: O(n)