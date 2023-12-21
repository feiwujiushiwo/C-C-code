#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ�ص�ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���ѡ���м��С��Ԫ����Ϊ��׼Ԫ��
int choosePivot(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    return mid;
}

// ��������
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ��·���ŸĽ�
void quickSort(int arr[], int low, int high) {
    if (high - low + 1 <= 10) {
        insertionSort(arr, low, high);
        return;
    }
    
    int pivotIndex = choosePivot(arr, low, high);
    int pivot = arr[pivotIndex];
    int i = low, j = high;
    int k = low;
    
    while (k <= j) {
        if (arr[k] < pivot) {
            swap(&arr[i], &arr[k]);
            i++;
            k++;
        }
        else if (arr[k] > pivot) {
            swap(&arr[k], &arr[j]);
            j--;
        }
        else {
            k++;
        }
    }
    
    quickSort(arr, low, i - 1);
    quickSort(arr, j + 1, high);
}

// ��������
int main() {
    int arr[] = {9, 4, 2, 7, 1, 8, 3, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("ԭʼ���飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf("\n��������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
