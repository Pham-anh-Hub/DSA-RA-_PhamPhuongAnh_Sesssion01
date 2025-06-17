#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int *maxNumber = (int *)malloc(n * sizeof(int));
    int index = 0;

    int maxRight = numbers[n-1];
    maxNumber[index++] = maxRight;

    for (int i = n - 2; i >= 0; i--) {
        if (numbers[i] > maxRight) {
            maxRight = numbers[i];
            maxNumber[index++] = maxRight;
        }
    }

    // In ngược lại để đúng thứ tự trái sang phải
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", maxNumber[i]);
    }

    free(numbers);
    free(maxNumber);
    return 0;
}
