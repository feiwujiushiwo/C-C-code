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
        temp = list->data[i]; // 保存当前需要插入的元素
        
        low = 0;
        high = i - 1;
        
        // 进行折半查找
        while (low <= high) {
            mid = (low + high) / 2;
            
            // 找到合适的插入位置
            if (list->data[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (j = i - 1; j >= low; j--) {
            list->data[j + 1] = list->data[j];
        }
        
        // 将当前元素插入到合适的位置
        list->data[low] = temp;
    }
}

int main() {
    SeqList list;
    int i;

    // 初始化顺序表
    list.length = 10;
    for (i = 0; i < list.length; i++) {
        list.data[i] = 10 - i;
    }

    printf("排序前：");
    for (i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    // 调用折半插入排序算法
    binaryInsertionSort(&list);

    printf("排序后：");
    for (i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    return 0;
}
