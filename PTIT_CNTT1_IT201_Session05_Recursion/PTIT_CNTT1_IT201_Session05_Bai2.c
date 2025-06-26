#include <stdio.h>

int calSum(int n){
    if(n == 1){
        return 1;
    }
    return n + calSum(n-1);

}

int main(){
    int number;
    printf("Nhap vao so can tinh tong: ");
    scanf("%d", &number);
    printf("Tong = %d",calSum(number));
}
