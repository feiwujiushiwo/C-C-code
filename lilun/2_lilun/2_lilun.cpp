#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// ����ջ�ṹ
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack *s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// �ж�ջ�Ƿ�����
int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// ��ջ
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->data[++(s->top)] = c;
}

// ��ջ
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

// �ж��ַ����Ƿ�Ϊ����
int isPalindrome(char *str) {
    int len = strlen(str);
    Stack s;
    initStack(&s);
    
    // ���ַ�������ַ�ѹ��ջ��
    for (int i = 0; i < len-1; i++) {
        push(&s, str[i]);
    }
    
    // ��ջ�е��ַ���������������ַ����е��ַ��Ƚ�
    for (int i = 0; i < len-1; i++) {
        if (pop(&s) != str[i]) {
            return 0; // ���ǻ���
        }
    }
    
    return 1; // �ǻ���
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}