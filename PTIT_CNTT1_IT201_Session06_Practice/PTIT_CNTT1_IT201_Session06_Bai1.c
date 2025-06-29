#include <stdio.h>

int binaryNumber(int n) {
    if (n==0) {
        return 0;
    }
    binaryNumber(n/2);
    printf("%d",n%2);
    // Theo cấu trúc Call Stack, Last In First Out
    // sau khi gọi duyệt tất cả các hàm,
    // lần lượt các lệnh được đưa vào ngăn xếp, và được lấy ra theo cơ chế LIFO
}
int main() {
    int number;
    printf("Nhap gia tri so can quy doi nhi phan: ");scanf("%d", &number);
    binaryNumber(number);

}
