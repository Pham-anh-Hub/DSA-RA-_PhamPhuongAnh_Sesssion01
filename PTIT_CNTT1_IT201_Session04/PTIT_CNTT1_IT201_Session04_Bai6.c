#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[100];
    int age;
};
struct Student student;

int main() {
    int size;
    printf("Nhap so hoc sinh nhap mang: "); scanf("%d", &size);
    struct Student students[size];
    for (int i = 0; i < size; i++) {
        printf("ID sv %d: ", i+1); scanf("%d", &students[i].id);
        fflush(stdin);
        printf("Ten sv %d: ", i+1); scanf("%s", &students[i].name);
        fflush(stdin);
        printf("Tuoi sv %d: ", i+1); scanf("%d", &students[i].age);
    }
    for (int i = 0; i < size; i++) {
        printf("\n*********************************");
        printf("\nSinh vien %d: ", i+1);
        printf("\nID: %d ", students[i].id);
        printf("\nTen: %s ", students[i].name);
        printf("\nTuoi: %d ", students[i].age);
        printf("\n*********************************");
    }
}