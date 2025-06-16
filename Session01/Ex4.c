#include <stdio.h>

int main() {
    // Cách 1:
    int n;
    printf("Nhap n: ");
    scanf("%d\n", &n);
    int sum=0;
    for (int i=1; i<=n; i++) {
        sum+=i;
    }
    printf("Sum = %d\n", sum);
    // Độ phức tạp không gian 1: O(n)


    //Cách 2:
    int total = n*(n+1)/2;
    printf("Total = %d", total);
    // Độ phức tạp không gian 2: O(1)

    return 0;
}