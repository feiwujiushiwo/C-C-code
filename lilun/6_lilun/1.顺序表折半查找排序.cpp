#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

void binaryInsertionSort(SeqList *list) {
    int i, j, low, high, mid;
    int temp;

    for (i = 1; i < list->length; i++) {
        temp = list->data[i]; // ���浱ǰ��Ҫ�����Ԫ��
        
        low = 0;
        high = i - 1;
        
        // �����۰����
        while (low <= high) {
            mid = (low + high) / 2;
            
            // �ҵ����ʵĲ���λ��
            if (list->data[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (j = i - 1; j >= low; j--) {
            list->data[j + 1] = list->data[j];
        }
        
        // ����ǰԪ�ز��뵽���ʵ�λ��
        list->data[low] = temp;
    }
}

int main() {
    SeqList list;
    int i;

    // ��ʼ��˳���
    list.length = 10;
    for (i = 0; i < list.length; i++) {
        list.data[i] = 10 - i;
    }

    printf("����ǰ��");
    for (i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    // �����۰���������㷨
    binaryInsertionSort(&list);

    printf("�����");
    for (i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    return 0;
}
