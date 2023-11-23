#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

typedef struct BNode
{
    int num;
    char op;
    struct BNode* lchild, * rchild;
}*BTree,BNode;

typedef struct TreeNode
{
    BTree data;
    struct TreeNode* next;
}*Tstack, TNode;

typedef struct OptrNode
{
    char optr;
    struct OptrNode* next;
}*Ostack,ONode;

char PopNoPrint(Ostack& os)
{
    if(os)
    {
        char temp = os->optr;
        Ostack t = os;
        os = os->next;
        delete t;
        //不打印，返回值
        return temp;
    }
}

char TOP(Ostack os)
{
    if(os)
    {
        return os ->optr;
    }
}

BTree PopNoPrint(Tstack& ts)//把返回值改成了BTree
{
    if(ts)
    {
        BTree temp = ts->data;
        Tstack t = ts;
        ts = ts->next;
        delete t;
        //不打印，返回值
        return temp;
    }
}

void InitStack(Ostack& os,Tstack& ts)
{
    os = NULL;
    ts = NULL;
}

BTree CreateTree(char c,BTree& 1,BTree& r)
{
    BTree temp = new BNode;
    temp->op = c;
    temp->lchild = 1;;
    temp->rchild = r;
    return temp;
}

BTree CreateTree(int a, BTree& 1, BTree& r)
{
    
}