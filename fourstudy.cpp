#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int num;
int alpha[26];
int k = 0;
char list[26];

typedef struct{
    int weight;//node's weight
    int parent,lchild,rchild;//right and left child
}HTNode,*HuffmanTree;//hfm-encode-table

typedef char** HuffmanCode;

void Select(HuffmanTree HT,int sum,int &s1,int &s2){
    int i,min1=100,
}