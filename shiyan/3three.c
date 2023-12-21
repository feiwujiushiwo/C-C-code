#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define YES 1
#define NO 0

char V[20];
char D[20];

int BF(char *D, char *V) {
    int i = 0, j = 0;
    while (i < strlen(D) && j < strlen(V)) {
        if (D[i] == V[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= strlen(V)) return YES;
    else return NO;
}

int BFjudge(char *D, char *V) {
    int flag = 0;
    int i, j, m;
    char temp[20];
    m = strlen(V);
    for (i = m, j = 0; j < m; j++) V[i++] = V[j];
    V[2 * m] = '\0';

    for (i = 0;; i++) {
        for (j = 0; j < m; j++) temp[j] = V[i + j];
        temp[m] = '\0';
        flag = BF(D, temp);
        if (flag) break;
        else if (i >= m) return NO;
        else continue;
    }
    return YES;
}

int PRINThand() {
    FILE *fp1, *fp2;
    int i = 0, k = 0;
    int s[20];

    printf("\n输入样例（病毒 人#输入0 0结束）：\n");
    while (1) {
        scanf("%s", &V[i]);
        scanf("%s", &D[i]);
        if (V[i] == '0' && D[i] == '0') break;

        if (BFjudge(D, V) == 1) s[k] = 1;
        else s[k] = 0;
        k++;
    }
    printf("输出样例：\n");
    for (k = 0; s[k] < 2; k++) {
        if (s[k] == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

int main() {
    int key = 0, Num;
    while (1) {
        printf("实验三\n");
        PRINThand(); break;
    }
}
