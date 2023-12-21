// Project7C.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#define MAX_VERtEX_NUM 20
#define VertexType int
struct Edge {
    VertexType head;
    VertexType tail;
    VertexType weight;
};
#define edge Edge[MAX_VERtEX_NUM];

//���帨������
typedef struct {
    VertexType value;//��������
    int sign;//ÿ�����������ļ���
}assist[MAX_VERtEX_NUM];

assist assists;

//qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������
int cmp(const void* a, const void* b) {
    return  ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
//��ʼ����ͨ��
void CreateUDN(Edge* edges, int* vexnum, int* arcnum) {
    printf("������ͨ���ı�����\n");
    scanf("%d %d", &(*vexnum), &(*arcnum));
    printf("������ͨ���Ķ��㣺\n");
    for (int i = 0; i < (*vexnum); i++) {
        scanf("%d", &(assists[i].value));
        assists[i].sign = i;
    }
    printf("������ߵ���ʼ����յ㼰Ȩ�أ�\n");
    for (int i = 0; i < (*arcnum); i++) {
        //scanf("%d,%d,%d", &(*edges)[i].head, &(*edges)[i].tail, &(*edges)[i].weight);
        scanf("%d,%d,%d", &(edges[i].head), &(edges[i].tail), &(edges[i].weight));
    }
}
//��assists�������ҵ�����point��Ӧ��λ���±�
int Locatevex(int vexnum, int point) {
    for (int i = 0; i < vexnum; i++) {
        if (assists[i].value == point) {
            return i;
        }
    }
    return -1;
}
int main() {

    int arcnum, vexnum;
    Edge edges[MAX_VERtEX_NUM];
    CreateUDN(edges, &vexnum, &arcnum);
    //����ͨ���е����б߽����������򣬽���Ա�����edges������
    qsort(edges, arcnum, sizeof(edges[0]), cmp);
    //����һ���յĽṹ�����飬���ڴ����С������
    Edge minTree[MAX_VERtEX_NUM];
    //����һ�����ڼ�¼��С�������бߵ������ĳ���
    int num = 0;
    //�������еı�
    for (int i = 0; i < arcnum; i++) {
        //�ҵ��ߵ���ʼ����ͽ�������������assists�е�λ��
        int head = Locatevex(vexnum, edges[i].head);
        int tail = Locatevex(vexnum, edges[i].tail);
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������·
        if (head != -1 && tail != -1 && assists[head].sign != assists[tail].sign) {
            //��¼�ñߣ���Ϊ��С����������ɲ���
            minTree[num] = edges[i];
            //����+1
            num++;
            //���¼����������Ķ�����ȫ������Ϊһ����
            for (int k = 0; k < vexnum; k++) {
                if (assists[k].sign == assists[tail].sign) {
                    assists[k].sign = assists[head].sign;
                }
            }
            //���ѡ��ıߵ������Ͷ��������1��֤����С�������Ѿ��γɣ��˳�ѭ��
            if (num == vexnum - 1) {
                break;
            }
        }
    }
    //������
    for (int i = 0; i < vexnum - 1; i++) {
        printf("%d,%d\n", minTree[i].head, minTree[i].tail);
    }
    return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
