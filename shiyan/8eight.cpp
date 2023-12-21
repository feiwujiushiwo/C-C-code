#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float score;
} student;

void InsertSort(student a[], int n) {
    int i, j;
    student temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j].score < temp.score) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

int main() {
    int capacity = 5; 
    int n = 0; // ѧ������
    student *a = (student *)malloc(capacity * sizeof(student));

    printf("����ѧ�������ͳɼ������� 0 0 ��������\n");
    while (1) {
        if (n == capacity) {
            capacity *= 2;
            a = (student *)realloc(a, capacity * sizeof(student));
        }

        scanf("%s %f", a[n].name, &a[n].score);

        if (a[n].score == 0 && strcmp(a[n].name, "0") == 0) {
            break;
        }

        n++;
    }

    InsertSort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", i + 1, a[i].name, a[i].score);
    }

    free(a);
    return 0;
}
