#include <stdio.h>

int paths(int a, int b, int row, int col) {
    if (a == row - 1 || b == col - 1) {
        return 1;
    }

    return paths(a + 1, b, row, col) + paths(a, b + 1, row, col);
}

int main() {
    // int i, j, row, col;
   printf("%d", paths(0,0,2,3)) ;
}