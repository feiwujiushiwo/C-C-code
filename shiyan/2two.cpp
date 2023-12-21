#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 20

typedef struct {
    float data[MaxSize];
    int top;
} OperandStack;

typedef struct {
    char data[MaxSize];
    int top;
} OperatorStack;

void InitOperandStack(OperandStack *S) { S->top = -1; }

void InitOperatorStack(OperatorStack *S) { S->top = -1; }

int PushOperand(OperandStack *S, float x) {
    if (S->top == MaxSize - 1) {
        printf("Õ»Âú");
        return 0;
    }
    S->data[++S->top] = x;
    return 1;
}

int PushOperator(OperatorStack *S, char x) {
    if (S->top == MaxSize - 1) {
        printf("Õ»Âú");
        return 0;
    }
    S->data[++S->top] = x;
    return 1;
}

float PopOperand(OperandStack *S) {
    float elem = S->data[S->top];
    S->top--;
    return elem;
}

char PopOperator(OperatorStack *S) {
    char operato = S->data[S->top];
    S->top--;
    return operato;
}

int getIndex(char theta) {
    int index = 0;
    switch (theta) {
        case '+':
            index = 0;
            break;
        case '-':
            index = 1;
            break;
        case '*':
            index = 2;
            break;
        case '/':
            index = 3;
            break;
        case '(':
            index = 4;
            break;
        case ')':
            index = 5;
            break;
        case '#':
            index = 6;
        default:
            break;
    }
    return index;
}

char getPriority(char theta1, char theta2) {
    const char priority[][7] =
        {
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'<', '<', '<', '<', '<', '=', '0'},
            {'>', '>', '>', '>', '0', '>', '>'},
            {'<', '<', '<', '<', '<', '0', '='},
        };

    int index1 = getIndex(theta1);
    int index2 = getIndex(theta2);

    return priority[index1][index2];
}

float OperateNum(float elem1, float elem2, char s) {
    float res;
    switch (s) {
        case '+':
            res = elem1 + elem2;
            break;
        case '-':
            res = elem1 - elem2;
            break;
        case '*':
            res = elem1 * elem2;
            break;
        case '/':
            res = elem1 / elem2;
    }
    return res;
}

float GetRes(char *s, OperandStack *S1, OperatorStack *S2) {
    int x = 0;
    int muti = 1;
    char prior = '0';
    char *str;
    int j = 0;
    float elem1, elem2;
    float res = 0;
    char operato;
    PushOperator(S2, '#');
    s[strlen(s) - 1] = '#';
    int p = 0;
    char ch = s[p];
    while (!(ch == '#' && S2->data[S2->top] == '#')) {
        if (ch >= '0' && ch <= '9') {
            str = (char *)malloc(sizeof(ch) * 10);
            while (s[p] >= '0' && s[p] <= '9') {
                str[j++] = s[p++];
            }
            for (int k = j - 1; k >= 0; k--) {
                x += (str[k] - '0') * muti;
                muti *= 10;
            }
            j = 0;
            muti = 1;
            PushOperand(S1, x);
            ch = s[p];
            x = 0;
            free(str);
        } else {
            prior = getPriority(S2->data[S2->top], ch);
            if (prior == '<') {
                PushOperator(S2, ch);
                ch = s[++p];
            } else if (prior == '=') {
                PopOperator(S2);
                ch = s[++p];
            } else if (prior == '>') {
                elem2 = PopOperand(S1);
                elem1 = PopOperand(S1);
                operato = PopOperator(S2);
                res = OperateNum(elem1, elem2, operato);
                PushOperand(S1, res);
            }
        }
    }
    res = PopOperand(S1);
    return res;
}

int main() {
    OperandStack S1;
    OperatorStack S2;
    char s[50] = "init";
    float res;
    float li[20];
    int i = 0;

    InitOperandStack(&S1);
    InitOperatorStack(&S2);

    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "="))
            break;
        res = GetRes(s, &S1, &S2);
        li[i] = res;
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%.3f\n", li[j]); 
    }

    return 0;
}
