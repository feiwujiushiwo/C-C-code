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
	int weight;        //����Ȩֵ 
	int parent, lchild, rchild;
}HTNode, *HuffmanTree; //����������� 
 
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
	int temp = HT[s1].weight;     //��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
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
	for (i = 1; i <= n; i++) //����Ҷ�ӽ���Ȩֵ 
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
{ //��Ҷ�ӵ���������ÿ���ַ��ĺշ������룬�洢�ڱ����HC��
	int i, start, c, f;
	HC = new char*[n + 1];         						//����n���ַ�����ı����ռ� 
	char *cd = new char[n];							//������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\0';                            		//���������
	for (i = 1; i <= n; ++i)                               //����ַ���շ�������
	{
		start = n - 1;                          		//start��ʼʱָ����󣬼����������λ��
		c = i;
		f = HT[i].parent;                 			//fָ����c��˫�׽��
		while (f != 0)
		{                          					//��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
			--start;                          		//����һ��start��ǰָһ��λ��
			if (HT[f].lchild == c)
				cd[start] = '0';						//���c��f�����ӣ������ɴ���0
			else
				cd[start] = '1';                 		//���c��f���Һ��ӣ������ɴ���1
			c = f;
			f = HT[f].parent;             			//�������ϻ���
		}                                  			//�����i���ַ��ı���      
		HC[i] = new char[n - start];         			// Ϊ��i ���ַ��������ռ�
		strcpy(HC[i], &cd[start]);        			//����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}
	delete cd;                            			//�ͷ���ʱ�ռ�
}													// CreatHuffanCode
void Output(HuffmanTree HT, HuffmanCode HC)
{
	for (int i = 1; i <= 2 * k - 1; i++)
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
 
	for (int i = 1; i <= k; i++)
	{
		cout << list[i - 1] << ":" << HC[i];
		if (i != k)cout << " ";//�������һ�� 
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
			if (k != num - 1)cout << " ";//�������һ�� 
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
			if (s[i] == list[j])//������ַ���namelist��ĳ���ַ����
				cout << HC[j + 1];//������Ӧ���� 
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