// Project7C.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//定义辅助数组
typedef struct {
    VertexType value;//顶点数据
    int sign;//每个顶点所属的集合
}assist[MAX_VERtEX_NUM];

assist assists;

//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
int cmp(const void* a, const void* b) {
    return  ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
//初始化连通网
void CreateUDN(Edge* edges, int* vexnum, int* arcnum) {
    printf("输入连通网的边数：\n");
    scanf("%d %d", &(*vexnum), &(*arcnum));
    printf("输入连通网的顶点：\n");
    for (int i = 0; i < (*vexnum); i++) {
        scanf("%d", &(assists[i].value));
        assists[i].sign = i;
    }
    printf("输入各边的起始点和终点及权重：\n");
    for (int i = 0; i < (*arcnum); i++) {
        //scanf("%d,%d,%d", &(*edges)[i].head, &(*edges)[i].tail, &(*edges)[i].weight);
        scanf("%d,%d,%d", &(edges[i].head), &(edges[i].tail), &(edges[i].weight));
    }
}
//在assists数组中找到顶点point对应的位置下标
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
    //对连通网中的所有边进行升序排序，结果仍保存在edges数组中
    qsort(edges, arcnum, sizeof(edges[0]), cmp);
    //创建一个空的结构体数组，用于存放最小生成树
    Edge minTree[MAX_VERtEX_NUM];
    //设置一个用于记录最小生成树中边的数量的常量
    int num = 0;
    //遍历所有的边
    for (int i = 0; i < arcnum; i++) {
        //找到边的起始顶点和结束顶点在数组assists中的位置
        int head = Locatevex(vexnum, edges[i].head);
        int tail = Locatevex(vexnum, edges[i].tail);
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
        if (head != -1 && tail != -1 && assists[head].sign != assists[tail].sign) {
            //记录该边，作为最小生成树的组成部分
            minTree[num] = edges[i];
            //计数+1
            num++;
            //将新加入生成树的顶点标记全不更改为一样的
            for (int k = 0; k < vexnum; k++) {
                if (assists[k].sign == assists[tail].sign) {
                    assists[k].sign = assists[head].sign;
                }
            }
            //如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if (num == vexnum - 1) {
                break;
            }
        }
    }
    //输出语句
    for (int i = 0; i < vexnum - 1; i++) {
        printf("%d,%d\n", minTree[i].head, minTree[i].tail);
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
