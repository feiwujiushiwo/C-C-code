#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// 判断栈是否已满
int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// 入栈
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->data[++(s->top)] = c;
}

// 出栈
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

// 判断字符串是否为回文
int isPalindrome(char *str) {
    int len = strlen(str);
    Stack s;
    initStack(&s);
    
    // 将字符串逐个字符压入栈中
    for (int i = 0; i < len-1; i++) {
        push(&s, str[i]);
    }
    
    // 将栈中的字符逐个弹出，并与字符串中的字符比较
    for (int i = 0; i < len-1; i++) {
        if (pop(&s) != str[i]) {
            return 0; // 不是回文
        }
    }
    
    return 1; // 是回文
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