#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *Arr = (int*)malloc(10 * sizeof(int));
    int *number = (int *)calloc(10, sizeof(int));

    // int*: dùng để ép kiểu giá trị trả về của hàm

    for (int i = 0; i < 10; i++) {
        Arr[i] = i;
        number[i] = i;
    };

    for (int i=0; i<10; i++) {
        printf("%d  %d", Arr[i], number[i]);
    }

    Arr = (int*)realloc(Arr, 10 * sizeof(int));
    number = (int*)realloc(number, 10 * sizeof(int));

    return 0;
}
