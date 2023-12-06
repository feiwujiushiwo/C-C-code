#include <queue>

#define MVNum 100
#define MaxInt 32767

using namespace std;

typedef struct{
    int vex[MVNum]; //�����
    int arcs[MVNum][MVNum];//�ڽӾ�������ͼ����Ȩ�أ�1 ��ʾ�бߣ�0��ʾ�ޱߡ�
    int Vexnum;//������
    int arcnum; //����
}AMGraph;

int FirstAdjVex(AMGraph G,int u){
    int j;
    for(j=1;j<=G.vexnum;j++){
        if(G.arcs[u][j]==1)
        return j;
    }
    return 0;
}

int NextAdjVex(AMGraph G,int u,int w){
    int i,j;
    for(j=w+1;j<=G.vexnum;j++){
        if(G.arcs[u][j]==1)
        return j;
    }
    return 0;
}