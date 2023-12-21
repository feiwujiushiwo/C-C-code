#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define SIZE 10
#include <time.h>
typedef struct
{
    int data[MAX_SIZE]; // ˳����д洢������
    int length;         // ˳���ĳ���
} SeqList;
// partition�������ڻ��������У�ͨ���Ƚ�����Ԫ�غ�����Ԫ�صĴ�С����С������Ԫ�ص�Ԫ���Ƶ��Ͷˣ�����������Ԫ�ص�Ԫ���Ƶ��߶ˣ����ս�����Ԫ�ط�������λ�ã���������λ�á�
int partition(SeqList *list, int low, int high)
{
    int pivot = list->data[low]; // ѡȡ����Ԫ��
    while (low < high)
    {
        while (low < high && list->data[high] >= pivot)
        {
            high--;
        }
        list->data[low] = list->data[high]; // ��������Ԫ��С��Ԫ���Ƶ��Ͷ�

        while (low < high && list->data[low] <= pivot)
        {
            low++;
        }
        list->data[high] = list->data[low]; // ��������Ԫ�ش��Ԫ���Ƶ��߶�
    }
    list->data[low] = pivot; // ����Ԫ�ط�������λ��
    return low;              // ��������Ԫ�ص�λ��
}
// quickSort�����ǿ�������ĺ����㷨������������Ԫ�ص�λ�ý����л��ֳ����������У��������������зֱ���еݹ�����
void quickSort(SeqList *list, int low, int high)
{
    if (low < high)
    {
        int pivotPos = partition(list, low, high); // ����������
        quickSort(list, low, pivotPos - 1);        // ���������н�������
        quickSort(list, pivotPos + 1, high);       // ���������н�������
    }
}

void sort(SeqList *list)
{
    quickSort(list, 0, list->length - 1);
}
void initSeqList(SeqList *list)
{
    list->length = SIZE;
    srand((unsigned)time(NULL)); // �������������
    for (int i = 0; i < SIZE; i++)
    {
        list->data[i] = rand() % 100; // ����0��99�������
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
    // ��ʼ��˳��������
    initSeqList(&list);
    printf("����ǰ��");
    printSeqList(list);
    sort(&list);
    printf("�����");
    printSeqList(list);
    return 0;
}