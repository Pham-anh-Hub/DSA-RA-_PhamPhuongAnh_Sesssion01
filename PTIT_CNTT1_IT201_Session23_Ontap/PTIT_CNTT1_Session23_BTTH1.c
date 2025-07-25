#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct Student {
    int id;
    char name[20];
    bool status;
    float avg;
} Student;

typedef struct Node {
    Student *student;
    struct Node *next;
    struct Node *prev;
} Node;

// Tạo sinh viên mới
Student *createStudent() {
    Student *student = (Student *) malloc(sizeof(Student));
    if (student == NULL) {
        return NULL;
    }
    printf("Nhap ID sinh vien: ");
    scanf("%d", &student->id);
    getchar();

    printf("Nhap ten sinh vien: ");
    fgets(student->name, 20, stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Nhap trang thai sinh vien: ");
    scanf("%d", (int*)&student->status);

    printf("Nhap diem trung binh: ");
    scanf("%f", &student->avg);

    return student;
}

// Thêm sinh viên vào mảng
int addStudentlist(Student *studentList[MAX], int count, Student *student) {
    if (count == MAX) {
        printf("Danh sach sinh vien day!\n");
        return count;
    }
    studentList[count++] = student;
    printf("Them moi sinh vien thanh cong!\n");
    return count;
}

// In danh sách sinh viên
void printList(Student *studentList[MAX], int count) {
    if (count == 0) {
        printf("Danh sach sinh vien trong\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("\tID: %d\n", studentList[i]->id);
        printf("\tTen: %s\n", studentList[i]->name);
        printf("\tTrang thai: %s\n", studentList[i]->status ? "Active" : "Inactive");
        printf("\tDiem trung binh: %.2f\n", studentList[i]->avg);
    }
}

// Xóa sinh viên theo ID
int removeStudent(Student *studentList[MAX], int count, int ID) {
    if (count == 0) {
        printf("Danh sach sinh vien trong\n");
        return count;
    }
    for (int i = 0; i < count; i++) {
        if (studentList[i]->id == ID) {
            Student *temp = studentList[i];
            for (int j = i; j < count - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            count--;
            free(temp);
            printf("Xoa sinh vien thanh cong!\n");
            return count;
        }
    }
    printf("Khong tim thay sinh vien co ID: %d\n", ID);
    return count;
}

// Cập nhật thông tin sinh viên
void updateStudent(Student *studentList[MAX], int count, int ID) {
    if (count == 0) {
        printf("Danh sach sinh vien trong\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (studentList[i]->id == ID) {
            getchar(); // Clear newline
            printf("Nhap ten thay doi: ");
            fgets(studentList[i]->name, 20, stdin);
            studentList[i]->name[strcspn(studentList[i]->name, "\n")] = '\0';
            printf("Cap nhat diem trung binh: ");
            scanf("%f", &studentList[i]->avg);
            printf("Cap nhat thong tin sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien can cap nhat\n");
}

// Tạo node danh sách liên kết
Node *createNode(Student *student) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->student = student;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Thêm sinh viên vào cuối danh sách liên kết đôi
Node *pushStudent(Node *head, Student *student) {
    Node *inactiveStd = createNode(student);
    if (inactiveStd == NULL) return NULL;
    if (head == NULL) return inactiveStd;

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = inactiveStd;
    inactiveStd->prev = current;
    return head;
}

// Lọc sinh viên không hoạt động (status == false)
Node *inActiveStudent(Node *head, Student *studentList[MAX], int count) {
    for (int i = 0; i < count; i++) {
        if (studentList[i] != NULL && studentList[i]->status == false) {
            head = pushStudent(head, studentList[i]);
        }
    }
    return head;
}

// Cập nhật status và đưa vào danh sách không hoạt động nếu cần
Node *updateStatus(Node *head, Student *studentList[MAX], int count, int ID) {
    if (count == 0) {
        printf("Danh sach sinh vien trong\n");
        return head;
    }
    for (int i = 0; i < count; i++) {
        if (studentList[i]->id == ID && studentList[i]->status == true) {
            studentList[i]->status = false;
            head = pushStudent(head, studentList[i]);
            printf("Cap nhat trang thai thanh cong!\n");
            return head;
        }
    }
    printf("Khong tim thay sinh vien hoac trang thai da 'Inactive'\n");
    return head;
}

// In danh sách sinh viên không hoạt động
void printInactive(Node *head) {
    if (head == NULL) {
        printf("Danh sach sinh vien khong hoat dong trong\n");
        return;
    }
    Node *current = head;
    printf("Danh sach sinh vien khong hoat dong:\n");
    while (current != NULL) {
        printf("ID: %d | Ten: %s | Trang thai: %s | Diem: %.2f\n",
               current->student->id,
               current->student->name,
               current->student->status ? "Active" : "Inactive",
               current->student->avg);
        current = current->next;
    }
}
// Hàm merge
void merge(Student *studentList[MAX], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    Student **leftArr = (Student **)malloc(leftSize * sizeof(Student *));
    Student **rightArr = (Student **)malloc(rightSize * sizeof(Student *));

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = studentList[start + i];

    for (int j = 0; j < rightSize; j++)
        rightArr[j] = studentList[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i]->avg <= rightArr[j]->avg) {
            studentList[k++] = leftArr[i++];
        } else {
            studentList[k++] = rightArr[j++];
        }
    }

    while (i < leftSize) {
        studentList[k++] = leftArr[i++];
    }

    while (j < rightSize) {
        studentList[k++] = rightArr[j++];
    }

    free(leftArr);
    free(rightArr);
}

// Hàm merge sort
void merge_sort(Student *studentList[MAX], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    merge_sort(studentList, start, mid);
    merge_sort(studentList, mid + 1, end);
    merge(studentList, start, mid, end);
}
void bubblesort(Student *studenList[MAX], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (studenList[j]->id > studenList[j + 1]->id) {
                Student *temp = studenList[j];
                studenList[j] = studenList[j + 1];
                studenList[j + 1] = temp;
            }
        }
    }
}

void binarySearch(Student *studentList[MAX], int start, int end, int ID) {
    while (start <= end) {
        int mid = (start+end)/2;
        if (studentList[mid]->id == ID) {
            printf("Sinh vien can tim:\n");
            printf("\tID: %d\n", studentList[mid]->id);
            printf("\tTen: %s\n", studentList[mid]->name);
            printf("\Trang thai: %s\n", studentList[mid]->status ? "Active" : "Inactive");
            printf("\tDiem trung binh: %.2f\n", studentList[mid]->avg);
            return;
        }else if (studentList[mid]->id > ID) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
}

void linearSearch(Student *studentList[MAX], int count, int ID) {
    for (int i = 0; i < count; i++) {
        if (studentList[i]->id == ID) {
            printf("Sinh vien can tim:\n");
            printf("\tID: %d\n", studentList[i]->id);
            printf("\tTen: %s\n", studentList[i]->name);
            printf("\tTrang thai: %s\n", studentList[i]->status ? "Active" : "Inactive");
            printf("\tDiem trung binh: %.2f\n", studentList[i]->avg);
            return;
        }
    }
}



int main() {
    int choice;
    Node *head = NULL;
    Student *studentList[MAX];
    int count = 0;
    do {
        printf("\n------- MENU -------\n");
        printf("1. Them moi sinh vien\n");
        printf("2. Hien thi sinh vien\n");
        printf("3. Xoa sinh vien theo ID\n");
        printf("4. Cap nhat sinh vien\n");
        printf("5. Thay doi trang thai sinh vien\n");
        printf("6. Sap xep sinh vien\n");
        printf("7. Tim kiem sinh vien\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Student *newStudent = createStudent();
                count = addStudentlist(studentList, count, newStudent);
                head = inActiveStudent(head, studentList, count);
                break;
            }
            case 2:
                printList(studentList, count);
                printInactive(head);
                break;
            case 3: {
                int removeId;
                printf("Nhap ID sinh vien can xoa: ");
                scanf("%d", &removeId);
                count = removeStudent(studentList, count, removeId);
                break;
            }
            case 4: {
                int updateId;
                printf("Nhap ID sinh vien can cap nhat: ");
                scanf("%d", &updateId);
                updateStudent(studentList, count, updateId);
                break;
            }
            case 5: {
                int updateStatusID;
                printf("Nhap ID sinh vien can doi trang thai: ");
                scanf("%d", &updateStatusID);
                head = updateStatus(head, studentList, count, updateStatusID);
                break;
            }
            case 6:
                merge_sort(studentList, 0, count-1);

                printList(studentList, count);
                break;
            case 7:
                int choiceSearch, idSearch;
                printf("Nhap id sinh vien can tim: ");scanf("%d", &idSearch);
                printf("1. Binary Search\n2. LinearSearch\nLua chon cua ban: ");
                scanf("%d", &choiceSearch);

                getchar();
                if (choiceSearch == 1) {
                    binarySearch(studentList, 0, count-1, idSearch);
                }else if (choiceSearch == 2) {
                    linearSearch(studentList,count,idSearch);
                }
                break;
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    // Giải phóng vùng nhớ trước khi thoát
    for (int i = 0; i < count; i++) {
        free(studentList[i]);
    }
    free(head);

    return 0;
}
