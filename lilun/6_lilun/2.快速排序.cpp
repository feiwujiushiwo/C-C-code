#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define SIZE 10
#include <time.h>
typedef struct
{
    int data[MAX_SIZE]; // 顺序表中存储的数据
    int length;         // 顺序表的长度
} SeqList;
// partition函数用于划分子序列，通过比较枢轴元素和其他元素的大小，将小于枢轴元素的元素移到低端，将大于枢轴元素的元素移到高端，最终将枢轴元素放入最终位置，并返回其位置。
int partition(SeqList *list, int low, int high)
{
    int pivot = list->data[low]; // 选取枢轴元素
    while (low < high)
    {
        while (low < high && list->data[high] >= pivot)
        {
            high--;
        }
        list->data[low] = list->data[high]; // 将比枢轴元素小的元素移到低端

        while (low < high && list->data[low] <= pivot)
        {
            low++;
        }
        list->data[high] = list->data[low]; // 将比枢轴元素大的元素移到高端
    }
    list->data[low] = pivot; // 枢轴元素放入最终位置
    return low;              // 返回枢轴元素的位置
}
// quickSort函数是快速排序的核心算法，它根据枢轴元素的位置将序列划分成两个子序列，并对两个子序列分别进行递归排序
void quickSort(SeqList *list, int low, int high)
{
    if (low < high)
    {
        int pivotPos = partition(list, low, high); // 划分子序列
        quickSort(list, low, pivotPos - 1);        // 对左子序列进行排序
        quickSort(list, pivotPos + 1, high);       // 对右子序列进行排序
    }
}

void sort(SeqList *list)
{
    quickSort(list, 0, list->length - 1);
}
void initSeqList(SeqList *list)
{
    list->length = SIZE;
    srand((unsigned)time(NULL)); // 设置随机数种子
    for (int i = 0; i < SIZE; i++)
    {
        list->data[i] = rand() % 100; // 生成0到99的随机数
    }
}
void printSeqList(SeqList list)
{
    printf("SeqList: ");
    for (int i = 0; i < list.length; i++)
    {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}
int main()
{
    SeqList list;
    // 初始化顺序表的数据
    initSeqList(&list);
    printf("排序前：");
    printSeqList(list);
    sort(&list);
    printf("排序后：");
    printSeqList(list);
    return 0;
}