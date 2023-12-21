#define MAX_SIZE 100 //假设最大容量为100
#include <stdio.h>
typedef struct
{
    int data[MAX_SIZE];
    int length;
} SeqList;
void insertionSort(SeqList *list)
{
    int i, j, temp;
    for (i = 1; i < list->length; i++)
    {
        temp = list->data[i];
        j = i - 1;
        while (j >= 0 && list->data[j] > temp)
        {
            list->data[j+1] = list->data[j];
            j--;
        }
        list->data[j+1] = temp;
    }
}
void display(SeqList list)
{
    int i;
    for (i = 0; i < list.length; i++)
        printf("%d ", list.data[i]);
    printf("\n");
}

int main()
{
    SeqList list = {{5, 3, 8, 2, 1}, 5};

    printf("Before sorting: ");
    display(list);

    insertionSort(&list);

    printf("After sorting: ");
    display(list);

    return 0;
}
