#include <stdio.h>

void printDouble(int n){
    int i=1;
    while(i<n){
        printf("%d\n",i);
        i*=2;
    }
}

int main(){
    printDouble(40);
    return 0;
}
// theo hàm trên <=> i=2^k  (với k sẽ bằng số lần lặp của vòng lặp while trên)
// mà vòng lặp thỏa mãn với i < n <==>  2^k < n ---> k < log(n)

// ==> Độ phức tạp của thuật toán trên: O(log(n))

