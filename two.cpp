// ջ����е�Ӧ��.cpp: �������̨Ӧ�ó������ڵ㡣

#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREASE 10
#define SElemType int
#define Status int
#define OK 1
#define OVERFLOW -1
#define ERROR 0

//��������ȼ���   
char Prior[7][7] =
{       // '+' '-' '*' '/' '(' ')' '#'   
  /*'+'*/'>','>','<','<','<','>','>',  //��ջ�еķ����ǼӺ�ʱ���˼Ӻ�����һ����������бȽ����ȼ�
  /*'-'*/'>','>','<','<','<','>','>',  //���漸������
  /*'*'*/'>','>','>','>','<','>','>',
  /*'/'*/'>','>','>','>','<','>','>',
  /*'('*/'<','<','<','<','<','=',' ',
  /*')'*/'>','>','>','>',' ','>','>',
  /*'#'*/'<','<','<','<','<',' ','='
};
char Precede(int a, int b) {//�ж����ȼ�
  return Prior[a][b];
}

typedef struct {
  SElemType *base;
  SElemType *top;
  int stacksize;
}SqStack;

//�����ջS
Status InitStack(SqStack &S) {
  S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
  if (!S.base) return OVERFLOW;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

//��ջ����
Status Push(SqStack &S, SElemType e) {
  if (S.top - S.base >= S.stacksize) {    //ջ����׷�ӿռ�
    S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREASE) * sizeof(SElemType));
    if (!S.base) return ERROR;      //�洢�ռ����ʧ��
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREASE;
  }
  *S.top = e;
  S.top++;
  return OK;
}

//��ջ����
Status Pop(SqStack &S, SElemType &e) {
  if (S.top == S.base) return ERROR;
  e = *--S.top;
  return e;
}

//ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType &e) {
  if (S.top == S.base) {     //���ջΪ�գ����ش���
    return ERROR;
  }
  e = *(S.top - 1);
  return e;
}

int change(char a) {           //���ַ�ת��������
  if (a == '+') return 0;    //��Ҫ����Ϊ������ջΪint��  
  if (a == '-') return 1;    //������洢��ջ��
  if (a == '*') return 2;
  if (a == '/') return 3;
  if (a == '(') return 4;
  if (a == ')') return 5;
  if (a == '#') return 6;
  else return a-48;
}

//�ж��ǲ��������
int In(char c) {
  if (c-48>=0 && c-48<= 9) return ERROR;
  else return OK;
}

//��������
int Operator(int a, int theta, int b) {    
  if (theta == 0) return a + b;
  if (theta == 1) return a - b;
  if (theta == 2) return a*b;
  if (theta == 3) return a/b;
}

//������ʽ����ֵ
int EvaluateExperession() {
  SqStack optr; //�����ջ
  SqStack opnd; //������ջ
  InitStack(optr);  //��ʼ��
  InitStack(opnd);  //��ʼ��

  Push(optr, 6);    //��ʼջ��Ԫ��Ϊ#��������6��ʾ
  char c[50];       //���ַ�����������������ı��ʽ
  int i=0,  x,  result;
  cin >> c;         //������ʽ
  do
  {
    if (!In(c[i])) {     //�������������������������ջ
      Push(opnd, change(c[i]));
      i++;
    }
    else {               //����������Ƚ����ȼ���������ز���
      switch (Precede(GetTop(optr, x), change(c[i]))) {
      case '<':        //��ǰջ��Ԫ�����ȼ��ͣ����������ջ
        Push(optr, change(c[i]));
        i++;
        break;
      case '=':        //�����������ȣ�Ϊ�������ţ�ȡ��
        Pop(optr, x);
        i++; 
        break;
      case '>':        //��ǰջ����������ȼ��ߣ����м���
        int a, b, theta;
        Pop(optr, theta);  //ȡ��ǰջ�������
        Pop(opnd, b);      //ȡջ��������b������ջ��ɾ��
        Pop(opnd, a);      //ȡջ��������a������ջ��ɾ��
        Push(opnd, Operator(a, theta, b));   //���м��㣬��������   
        break;
      }
    }
  } while ( c[i] );
  return GetTop(opnd, result);
}

int main()
{
  cout << "������һ�����ʽ����#��������";
  cout << "����ý��Ϊ��"<<EvaluateExperession() << endl;
  return 0;
}