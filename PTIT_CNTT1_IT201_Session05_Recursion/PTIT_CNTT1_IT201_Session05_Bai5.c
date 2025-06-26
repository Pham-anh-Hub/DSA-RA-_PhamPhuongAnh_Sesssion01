#include <stdio.h>
#include <string.h>

int checkPalindrome(char str[50], int size, int start) {
    if (start >= size/2) {
        return 1;
    }
    if (str[start] != str[size - start - 1]) {
        return 0;
    }
   return checkPalindrome(str, size, start + 1);

}
int main() {
    char string[50];
    printf("Vui long nhap vao chuoi kiem tra: ");
    scanf("%s", &string);
    if (checkPalindrome(string, strlen(string), 0)) {
        printf("Day la chuoi doi xung");
    }else {
        printf("Day khong phai chuoi doi xung");
    }
}