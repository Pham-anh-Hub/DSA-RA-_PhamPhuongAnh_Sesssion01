#include <stdio.h>

void printNumber(int n, int i){
    if(i > n){
        return;
    }
    printf("%d ", i);
    i++;
    printNumber(n,i);
}

int main(){
    printNumber(5,1);
}
