// 栈与队列的应用.cpp: 定义控制台应用程序的入口点。

#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREASE 10
#define SElemType int
#define Status int
#define OK 1
#define OVERFLOW -1
#define ERROR 0

//运算符优先级表   
char Prior[7][7] =
{       // '+' '-' '*' '/' '(' ')' '#'   
  /*'+'*/'>','>','<','<','<','>','>',  //当栈中的符号是加号时，此加号与下一个运算符进行比较优先级
  /*'-'*/'>','>','<','<','<','>','>',  //下面几行类似
  /*'*'*/'>','>','>','>','<','>','>',
  /*'/'*/'>','>','>','>','<','>','>',
  /*'('*/'<','<','<','<','<','=',' ',
  /*')'*/'>','>','>','>',' ','>','>',
  /*'#'*/'<','<','<','<','<',' ','='
};
char Precede(int a, int b) {//判断优先级
  return Prior[a][b];
}

typedef struct {
  SElemType *base;
  SElemType *top;
  int stacksize;
}SqStack;

//构造空栈S
Status InitStack(SqStack &S) {
  S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
  if (!S.base) return OVERFLOW;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

//入栈操作
Status Push(SqStack &S, SElemType e) {
  if (S.top - S.base >= S.stacksize) {    //栈满，追加空间
    S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREASE) * sizeof(SElemType));
    if (!S.base) return ERROR;      //存储空间分配失败
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREASE;
  }
  *S.top = e;
  S.top++;
  return OK;
}

//出栈操作
Status Pop(SqStack &S, SElemType &e) {
  if (S.top == S.base) return ERROR;
  e = *--S.top;
  return e;
}

//取栈顶元素
Status GetTop(SqStack S, SElemType &e) {
  if (S.top == S.base) {     //如果栈为空，返回错误
    return ERROR;
  }
  e = *(S.top - 1);
  return e;
}

int change(char a) {           //将字符转换成数字
  if (a == '+') return 0;    //主要是因为建立的栈为int型  
  if (a == '-') return 1;    //方便与存储到栈中
  if (a == '*') return 2;
  if (a == '/') return 3;
  if (a == '(') return 4;
  if (a == ')') return 5;
  if (a == '#') return 6;
  else return a-48;
}

//判断是不是运算符
int In(char c) {
  if (c-48>=0 && c-48<= 9) return ERROR;
  else return OK;
}

//进行运算
int Operator(int a, int theta, int b) {    
  if (theta == 0) return a + b;
  if (theta == 1) return a - b;
  if (theta == 2) return a*b;
  if (theta == 3) return a/b;
}

//输入表达式并求值
int EvaluateExperession() {
  SqStack optr; //运算符栈
  SqStack opnd; //运算数栈
  InitStack(optr);  //初始化
  InitStack(opnd);  //初始化

  Push(optr, 6);    //初始栈底元素为#，用数字6表示
  char c[50];       //用字符串数组来保存输入的表达式
  int i=0,  x,  result;
  cin >> c;         //输入表达式
  do
  {
    if (!In(c[i])) {     //如果不是运算符，将其进运算数栈
      Push(opnd, change(c[i]));
      i++;
    }
    else {               //是运算符，比较优先级并进行相关操作
      switch (Precede(GetTop(optr, x), change(c[i]))) {
      case '<':        //当前栈顶元素优先级低，新运算符入栈
        Push(optr, change(c[i]));
        i++;
        break;
      case '=':        //两个运算符相等，为左右括号，取出
        Pop(optr, x);
        i++; 
        break;
      case '>':        //当前栈顶运算符优先级高，进行计算
        int a, b, theta;
        Pop(optr, theta);  //取当前栈顶运算符
        Pop(opnd, b);      //取栈顶运算数b，并从栈中删除
        Pop(opnd, a);      //取栈顶运算数a，并从栈中删除
        Push(opnd, Operator(a, theta, b));   //进行计算，将计算结果   
        break;
      }
    }
  } while ( c[i] );
  return GetTop(opnd, result);
}

int main()
{
  cout << "请输入一个表达式（以#结束）：";
  cout << "计算得结果为："<<EvaluateExperession() << endl;
  return 0;
}