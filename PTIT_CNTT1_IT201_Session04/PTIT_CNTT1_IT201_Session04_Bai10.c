#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Student {
    char id[50];
    char name[100];
    int age;
};
struct Student student;

bool checkName(char studentName[50], char character) {
    for (int i = 0; i < strlen(studentName); i++) {
        if (studentName[i] == character || studentName[i] == toupper(character)) {
            return true;
        }
    }
    return false;
}


int main() {
    int size;
    printf("Nhap vap so luong sinh vien: "); scanf("%d", &size);
    struct Student arr[size];
    for (int i = 0; i < size; i++) {
        printf("Nhap ID sinh vien %d: ", i+1);scanf("%s", &arr[i].id);
        printf("Nhap ten sinh vien %d: ", i+1);scanf("%s", &arr[i].name);
        printf("Nhap tuoi sinh vien %d: ", i+1);scanf("%d", &arr[i].age);
        printf("*********\n");
    }
    fflush(stdin);
    char targetChar;
    printf("Nhap ky tu can kiem tra: "); scanf("%c", &targetChar);
    printf("SV can tim: \n");
    for (int i = 0; i < size; i++) {
        if (checkName(arr[i].name, targetChar)) {
            printf("{id: %s, name: %s, age: %d }\n",arr[i].id, arr[i].name, arr[i].age);
        }
    }

}