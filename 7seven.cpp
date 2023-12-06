#include <queue>

#define MVNum 100
#define MaxInt 32767

using namespace std;

typedef struct{
    int vex[MVNum]; //顶点表
    int arcs[MVNum][MVNum];//邻接矩阵，无向图，无权重，1 表示有边，0表示无边。
    int Vexnum;//顶点数
    int arcnum; //边数
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