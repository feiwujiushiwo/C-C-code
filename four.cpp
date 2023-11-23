#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int num;
int alpha[26];
int num2 = 0;
int k = 0;
char list[26];
 
typedef struct {
	int weight;        //结点的权值 
	int parent, lchild, rchild;
}HTNode, *HuffmanTree; //哈夫曼编码表 
 
typedef char** HuffmanCode;
 
void Select(HuffmanTree HT, int sum, int &s1, int &s2)
{
	int i, min1 = 100, min2 = 100;
	for (i = 1; i <= sum; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight < min1)
		{
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	int temp = HT[s1].weight;     //将原值存放起来，然后先赋予最大值，防止s1被重复选择
	HT[s1].weight = 100;
	for (i = 1; i <= sum; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight < min2)
		{
			min2 = HT[i].weight;
			s2 = i;
		}
	}
	HT[s1].weight = temp;
}
 
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
	int i;
	if (n <= 1) return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (i = 1; i <= m; i++)
	{
		HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
	}
	for (i = 1; i <= n; i++) //输入叶子结点的权值 
		HT[i].weight = alpha[i - 1];
	int s1, s2;
	for (i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
 
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{ //从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
	int i, start, c, f;
	HC = new char*[n + 1];         						//分配n个字符编码的编码表空间 
	char *cd = new char[n];							//分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';                            		//编码结束符
	for (i = 1; i <= n; ++i)                               //逐个字符求赫夫曼编码
	{
		start = n - 1;                          		//start开始时指向最后，即编码结束符位置
		c = i;
		f = HT[i].parent;                 			//f指向结点c的双亲结点
		while (f != 0)
		{                          					//从叶子结点开始向上回溯，直到根结点
			--start;                          		//回溯一次start向前指一个位置
			if (HT[f].lchild == c)
				cd[start] = '0';						//结点c是f的左孩子，则生成代码0
			else
				cd[start] = '1';                 		//结点c是f的右孩子，则生成代码1
			c = f;
			f = HT[f].parent;             			//继续向上回溯
		}                                  			//求出第i个字符的编码      
		HC[i] = new char[n - start];         			// 为第i 个字符编码分配空间
		strcpy(HC[i], &cd[start]);        			//将求得的编码从临时空间cd复制到HC的当前行中
	}
	delete cd;                            			//释放临时空间
}													// CreatHuffanCode
void Output(HuffmanTree HT, HuffmanCode HC)
{
	for (int i = 1; i <= 2 * k - 1; i++)
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
 
	for (int i = 1; i <= k; i++)
	{
		cout << list[i - 1] << ":" << HC[i];
		if (i != k)cout << " ";//多输出了一个 
	}
	cout << endl;
}
 
 
void Initalpha(int a[], string s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		int e = (int)s[i];
		if (e >= 97) a[e - 97]++;
		i++;
	}
	for (i = 0; i < 26; i++)
		if (a[i]) {
			num++;
		}
	for (i = 0; i < 26; i++)
		if (a[i]) {
			char e = (char)(i + 97);
			cout << e << ":" << a[i];
			if (k != num - 1)cout << " ";//多输出了一个 
			alpha[k] = a[i]; 
			list[k] = e;
			k++;
		}
	cout << endl;
}
 
 
void InitData(int fre[])
{
 
	for (int i = 0; i < 26; i++)
		fre[i] = 0;
	for (int i = 0; i < 26; i++)
		list[i] = 0;
	 k = 0; num2 = 0 ,num = 0;
	return;
}
void Translate(HuffmanCode HC, string s)
{
	int i = 0;
	while (s[i]) {
		int j = 0;
		while (j < 26)
		{
			if (s[i] == list[j])//如果该字符与namelist中某个字符相等
				cout << HC[j + 1];//输出其对应编码 
			j++;
		}
		i++;
	}
	cout << endl;
 
	i = 0;
	while (s[i]) {
		char e;
		e = s[i];
		cout << e;
		i++;
	}
	cout << endl;
}
 
int main()
{
	string s;
	while (cin >> s && s != "0")
	{
		
		InitData(alpha);
		Initalpha(alpha, s);
		HuffmanTree HT;
		HuffmanCode HC;
		CreateHuffmanTree(HT, k);
		CreatHuffmanCode(HT, HC, k);
		Output(HT, HC);
		Translate(HC, s);
	}
	return 0;
	
}