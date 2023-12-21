#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 50
#define CODEMAX 128
typedef struct HTNode
{
    int weight; // 结点权值
    char ch;
    struct HTNode *lchild, *rchild;
} HTNode;
// 统计字符频率
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
// 创建森林集合,字符转成结点
int InitTree(int *count, HTNode **HT)
{
    int j = 0;
    for (int i = 0; i < 26; i++) // 遍历count数组
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
    for (int i = 0; i < j; i++) // 遍历森林结点，对其权值进行冒泡排序
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
// 构建哈夫曼树
int HaffmanTree(HTNode **HT, int j, HTNode *&root)
{
    // 构建二叉树，操作后HT数组不存在，但结点通过链表连接在了一起
    while (j > 1)
    {
        HTNode *new_node = (HTNode *)malloc(sizeof(HTNode));
        new_node->ch = '0'; // 新生成结点字符赋值为'0'
        new_node->weight = HT[j - 1]->weight + HT[j - 2]->weight;
        new_node->lchild = HT[j - 1];
        new_node->rchild = HT[j - 2];
        HT[j - 2] = new_node;
        j--;
        Sort(HT, j);
    }
    // 现在HT中仅剩root结点
    root = HT[0];
    return 0;
}
char *charcode[128] = {0};
// 利用哈夫曼数进行编码
int Haffmancode(HTNode *p, char *buff, int len)
{
    buff[len] = 0;
    if (p->lchild == NULL && p->rchild == NULL) // 叶子结点
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
    char str[STRMAX]; // 输入字符串
    HTNode *HT[26];   // 临时存放全部森林结点指针
    HTNode *root;     // 存储哈夫曼数root结点地址
    char buff[1000];
    while (1)
    {
        gets(str);
        if (str[0] == '0')
            break;
        int count[26] = {0};
        CharCount(str, count);
        int j = InitTree(count, HT); // HT中存储了多少个结点
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
