#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 50
#define CODEMAX 128
typedef struct HTNode
{
    int weight; // ���Ȩֵ
    char ch;
    struct HTNode *lchild, *rchild;
} HTNode;
// ͳ���ַ�Ƶ��
void CharCount(char *str, int *count)
{
    for (int i = 0; i < strlen(str); i++)
        count[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            printf("%c:%d ", i + 'a', count[i]);
    }
    printf("\n");
}
// ����ɭ�ּ���,�ַ�ת�ɽ��
int InitTree(int *count, HTNode **HT)
{
    int j = 0;
    for (int i = 0; i < 26; i++) // ����count����
    {
        if (count[i] != 0)
        {
            HTNode *p = (HTNode *)malloc(sizeof(HTNode));
            p->weight = count[i];
            p->ch = 'a' + i;
            p->lchild = NULL;
            p->rchild = NULL;
            HT[j] = p;
            j++;
        }
    }
    return j;
}
void Sort(HTNode **HT, int j)
{
    HTNode *temp;
    for (int i = 0; i < j; i++) // ����ɭ�ֽ�㣬����Ȩֵ����ð������
    {
        for (int k = i + 1; k < j; k++)
        {
            if (HT[k]->weight > HT[i]->weight)
            {
                temp = HT[k];
                HT[k] = HT[i];
                HT[i] = temp;
            }
        }
    }
}
// ������������
int HaffmanTree(HTNode **HT, int j, HTNode *&root)
{
    // ������������������HT���鲻���ڣ������ͨ��������������һ��
    while (j > 1)
    {
        HTNode *new_node = (HTNode *)malloc(sizeof(HTNode));
        new_node->ch = '0'; // �����ɽ���ַ���ֵΪ'0'
        new_node->weight = HT[j - 1]->weight + HT[j - 2]->weight;
        new_node->lchild = HT[j - 1];
        new_node->rchild = HT[j - 2];
        HT[j - 2] = new_node;
        j--;
        Sort(HT, j);
    }
    // ����HT�н�ʣroot���
    root = HT[0];
    return 0;
}
char *charcode[128] = {0};
// ���ù����������б���
int Haffmancode(HTNode *p, char *buff, int len)
{
    buff[len] = 0;
    if (p->lchild == NULL && p->rchild == NULL) // Ҷ�ӽ��
    {
        charcode[p->ch] = strdup(buff);
        return 0;
    }
    buff[len] = '0';
    Haffmancode(p->lchild, buff, len + 1);
    buff[len] = '1';
    Haffmancode(p->rchild, buff, len + 1);
    return 0;
}
int main()
{
    char str[STRMAX]; // �����ַ���
    HTNode *HT[26];   // ��ʱ���ȫ��ɭ�ֽ��ָ��
    HTNode *root;     // �洢��������root����ַ
    char buff[1000];
    while (1)
    {
        gets(str);
        if (str[0] == '0')
            break;
        int count[26] = {0};
        CharCount(str, count);
        int j = InitTree(count, HT); // HT�д洢�˶��ٸ����
        Sort(HT, j);
        HaffmanTree(HT, j, root);
        Haffmancode(root, buff, 0);
        for (int i = 0; i < 128; i++)
        {
            if (charcode[i] == NULL)
                continue;
            printf("%c:%s ", i, charcode[i]);
        }
        printf("\n");
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                for (int j = 0; j < count[i]; j++)
                {
                    printf("%s",charcode[i+'a']);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
