#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so phan tu mang: ");
    scanf("%d", &size);
    if (0<size && size<1000) {
        int *numbers = (int *)malloc(size*sizeof(int));
       for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
       }
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }
        int size_2;
        printf("\nNhap so phan tu them vao mang: ");
        scanf ("%d", &size_2);
        numbers = realloc(numbers, (size_2+size)*sizeof(int));
        for (int i = size; i < size + size_2; i++) {
            scanf("%d", &numbers[i]);
        }
        printf("Mang sau khi them: ");
        for (int i = 0; i < size + size_2; i++) {
            printf("%d ", numbers[i]);
        } free(numbers);

    }else {
        printf("So luong phan tu mang khong hop le");
    }


}