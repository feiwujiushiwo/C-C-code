#include <stdio.h>
#include <stdlib.h>
// �������޴�
#define INF 100000
// ��ĸ���
#define V_SIZE 6
#define MVNum 100
typedef struct
{
    char vex[MVNum];        // �����
    int arcs[MVNum][MVNum]; // �ڽӾ���Ȩ��Ϊ����
    int Vexnum;             // ������
    int arcnum;             // ����
} AMGraph;
/*�������ܣ�
 * 	Floyd�㷨������ͼ��̾��룬�����·��
 *���������
 *	G	�ڽӾ���ͼ
 *	n		�����С,����ĸ���
 *	dist	���յ����е����̾���
 *start		������ʼ����
 *end ���յ��ﶥ��
 *  path ��¼·��ǰ��
 * */
void printPath(int i, int j, int p[][5]) // ���·��
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
    for (int k = 0; k < n; k++) // ѡ����˭��Ϊ��ת
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
    printf("%c��%c�����·������Ϊ��%d", start + 'A', end + 'A', dist[start][end]);
    printf("%c��%c�����·��Ϊ��", start + 'A', end + 'A', dist[start][end]);
    printPath(start, end, path);
    printf("%c\n",end+'A');
}
int main()
{
    while (1)
    {
        int V, E; // ���и�����·������
        AMGraph G;
        printf("��������и�����·���������ÿո����\n");
        scanf("%d %d", &V, &E);
        fflush(stdin); // ���������
        if (E == 0 && V == 0)
            break;
        G.Vexnum = V;
        G.arcnum = E;
        printf("��������е�����\n");
        for (int i = 0; i < V; i++)
            scanf("%c", &G.vex[i]);
        fflush(stdin); // ���������
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                G.arcs[i][j] = INF;
        }
        printf("���������֮��ľ��룬�ÿո����\n");
        for (int i = 0; i < E; i++)
        {
            char m1, m2; // ���������·���ĵص�
            int arc;     // ��
            scanf("%c %c %d", &m1, &m2, &arc);
            G.arcs[m1 - 'A'][m2 - 'A'] = arc;
            G.arcs[i][i] = 0;
            fflush(stdin); // ���������
        }
        printf("��������Ҫ������������֮������·�����ÿո����\n");
        char c1, c2; // �������������
        scanf("%c %c", &c1, &c2);
        fflush(stdin); // ���������
        Floyd(G, G.Vexnum, c1 - 'A', c2 - 'A');
    }
    return 0;
}
