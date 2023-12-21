#include <stdio.h>
#include <string.h>
#define INF 1000000
int calc(char *str, int l, int r)
{
    int pos = -1, pri = INF - 1, cur_pri, extra_pri = 0;
    // 找出优先级最小的符号，即最后运算的符号
    for (int i = l; i < r; i++)
    {
        cur_pri = INF;
        switch (str[i])
        {
        case '(':
            extra_pri += 100;
            break;
        case ')':
            extra_pri -= 100;
            break;
        case '+':
        case '-':
            cur_pri = 1 + extra_pri;
            break;
        case '*':
        case '/':
            cur_pri = 2 + extra_pri;
            break;
        }
        if (pri >= cur_pri)
        {
            pri = cur_pri;
            pos = i;
        }
    }
    if (pos == -1)
    {
        int num = 0;
        for (int i = l; i < r; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                continue;
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }
    else
    {
        int a = calc(str, l, pos);
        int b = calc(str, pos + 1, r); 
        switch (str[pos])
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
    }
    return 0;
}
int main()
{
    while (1)
    {
        char str[20];
        gets(str);
        if (str[0] == '=')
            break;
        int num = calc(str, 0, strlen(str));
        printf("%d\n", num);
    }
    return 0;
}