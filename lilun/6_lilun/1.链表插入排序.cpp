#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
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

        // 找到新节点在链表中的正确位置
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        // 在当前节点后插入新节点
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 对链表进行插入排序
Node* insertionSort(Node* head) {
    Node* sorted = NULL;
    Node* current = head;

    // 遍历链表中的每个节点
    while (current != NULL) {
        Node* next = current->next;

        // 将当前节点从原链表中分离
        current->next = NULL;

        // 将当前节点插入到已排序链表中的正确位置
        sortedInsert(&sorted, current);

        // 移动到下一个节点
        current = next;
    }

    return sorted;
}

// 输出链表内容
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

    // 创建链表
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

    // 执行插入排序
    head = insertionSort(head);      

    // 输出排序后的链表
    printf("排序后的链表: ");
    printList(head);

    return 0;
}

