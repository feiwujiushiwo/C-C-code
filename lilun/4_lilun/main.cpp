#include <stdio.h>
#include <stdlib.h>
// 代表无限大
#define INF 100000
// 点的个数
#define V_SIZE 6
#define MVNum 100
typedef struct
{
    char vex[MVNum];        // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵，权重为整数
    int Vexnum;             // 顶点数
    int arcnum;             // 边数
} AMGraph;
/*函数功能：
 * 	Floyd算法求无向图最短距离，并输出路径
 *输入参数：
 *	G	邻接矩阵图
 *	n		矩阵大小,即点的个数
 *	dist	接收到所有点的最短距离
 *start		接收起始顶点
 *end 接收到达顶点
 *  path 记录路径前驱
 * */
void printPath(int i, int j, int p[][5]) // 输出路径
{
    if (p[i][j]==-1)
       printf("%c-->",i+'A');
    else{
        printPath(i, p[i][j],p);
        printPath(p[i][j],j,p);
    }
}
void Floyd(AMGraph G, int n, int start, int end)
{
    int dist[n][n];
    int path[5][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = G.arcs[i][j];
            path[i][j] = -1;
        }
    }
    for (int k = 0; k < n; k++) // 选择以谁作为中转
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    printf("path:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    printf("%c到%c的最短路径长度为：%d", start + 'A', end + 'A', dist[start][end]);
    printf("%c到%c的最短路径为：", start + 'A', end + 'A', dist[start][end]);
    printPath(start, end, path);
    printf("%c\n",end+'A');
}
int main()
{
    while (1)
    {
        int V, E; // 城市个数和路径条数
        AMGraph G;
        printf("请输入城市个数和路径条数，用空格隔开\n");
        scanf("%d %d", &V, &E);
        fflush(stdin); // 清除缓冲区
        if (E == 0 && V == 0)
            break;
        G.Vexnum = V;
        G.arcnum = E;
        printf("请输入城市的名称\n");
        for (int i = 0; i < V; i++)
            scanf("%c", &G.vex[i]);
        fflush(stdin); // 清除缓冲区
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                G.arcs[i][j] = INF;
        }
        printf("请输入城市之间的距离，用空格隔开\n");
        for (int i = 0; i < E; i++)
        {
            char m1, m2; // 保存输入的路径的地点
            int arc;     // 弧
            scanf("%c %c %d", &m1, &m2, &arc);
            G.arcs[m1 - 'A'][m2 - 'A'] = arc;
            G.arcs[i][i] = 0;
            fflush(stdin); // 清除缓冲区
        }
        printf("请输入你要求哪两个城市之间的最短路径，用空格隔开\n");
        char c1, c2; // 待求的两个城市
        scanf("%c %c", &c1, &c2);
        fflush(stdin); // 清除缓冲区
        Floyd(G, G.Vexnum, c1 - 'A', c2 - 'A');
    }
    return 0;
}
