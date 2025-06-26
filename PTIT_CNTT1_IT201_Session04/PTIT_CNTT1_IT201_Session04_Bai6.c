#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[100];
    int age;
};
struct Student student; // Gọi ra

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
    int targetId;
    printf("Moi nhap id can tim: "); scanf("%d", &targetId);
    // linear search
    // for (int i = 0; i < size; i++) {
    //     if (students[i].id == targetId) {
    //         printf("\n*********************************");
    //         printf("\nSinh vien %d: ", i+1);
    //         printf("\nID: %d ", students[i].id);
    //         printf("\nTen: %s ", students[i].name);
    //         printf("\nTuoi: %d ", students[i].age);
    //         printf("\n*********************************");
    //     }
    // }

    // binary search
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (students[mid].id == targetId) {
            printf("\n*********************************");
            printf("\nSinh vien can tim: ");
            printf("\nID: %d ", students[mid].id);
            printf("\nTen: %s ", students[mid].name);
            printf("\nTuoi: %d ", students[mid].age);
            printf("\n*********************************");
            return;
        }else if (students[mid].id < targetId) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

}