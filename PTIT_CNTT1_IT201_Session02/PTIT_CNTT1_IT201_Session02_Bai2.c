#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int a=0, k=size-1, reverse[size];
    while (a<size && k>=0) {
        reverse[a] = arr[k];
        a++;
        k--;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", reverse[i]);
    }

}