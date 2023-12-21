#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void sortedInsert(Node** head, Node* newNode) {
    Node* current;

    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;

        // �ҵ��½ڵ��������е���ȷλ��
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        // �ڵ�ǰ�ڵ������½ڵ�
        newNode->next = current->next;
        current->next = newNode;
    }
}

// ��������в�������
Node* insertionSort(Node* head) {
    Node* sorted = NULL;
    Node* current = head;

    // ���������е�ÿ���ڵ�
    while (current != NULL) {
        Node* next = current->next;

        // ����ǰ�ڵ��ԭ�����з���
        current->next = NULL;

        // ����ǰ�ڵ���뵽�����������е���ȷλ��
        sortedInsert(&sorted, current);

        // �ƶ�����һ���ڵ�
        current = next;
    }

    return sorted;
}

// �����������
void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node* head = NULL;

    // ��������
    head = (Node*)malloc(sizeof(Node));
    head->data = 5;
    head->next = NULL;

    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 2;
    second->next = NULL;
    head->next = second;

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 4;
    third->next = NULL;
    second->next = third;

    Node* fourth = (Node*)malloc(sizeof(Node));
    fourth->data = 1;
    fourth->next = NULL;
    third->next = fourth;

    // ִ�в�������
    head = insertionSort(head);      

    // �������������
    printf("����������: ");
    printList(head);

    return 0;
}

