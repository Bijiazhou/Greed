//
// Created by 岳晨阳 on 2019/12/11.
//
//[Dijkstra]
//Dijkstra算法的贪心策略是选择集合𝐕−𝐒中选择这样一个点，比起该集合中的其它点到源的最短路径，
// 该点到源的最短路径的长度最短，并把该点加入𝑆中，相应地最短路径树𝑇也增加一条边
#include <stdio.h>
#include <string.h>

#define INF 0x03f3f3f3f
#define MaxV 100

//前驱节点列表
int preV[MaxV];
//是否加入S的标记表
int visited[MaxV];

//linkmatrix 输入有向图的权值
//lowlr最短受限路径
//numv是节点个数
void Dijkstra(int linkMatrix[][MaxV],int lowLR[MaxV],int numV, int beginV){
    int i,j,min,newCost;

    //初始化 所有的节点都未被分配
    memset(visited,0, sizeof(visited));

//    开始节点加入
    visited[beginV]=1;

//    更新受限路径和前驱结点
    for (int i = 0; i < numV; ++i) {
        lowLR[i] = linkMatrix[beginV][i];
        preV[i] = beginV;
    }

    lowLR[beginV]=0;    //受限路径
    preV[beginV]=-1;    //树根标记

//    beginv是第一个前驱节点
    int selectV = beginV;

    for (int i = 1; i < numV; ++i) {


        for (int j = 0; j < numV; ++j) { //更新受限路径
//            利用新加入S的selectV节点来更新V-S集合里面的所有的点到x的最短路径
            newCost = lowLR[selectV]+linkMatrix[selectV][j];
//            未经造访 且 路程端与当前的  更新
            if(visited[j] == 0 && newCost < lowLR[j]){
                lowLR[j]=newCost;
                preV[j]=selectV;
            }
        }

        //inf是极其大的意思
        min = INF;

//        比较从源节点到V-S 集合中所有点的最短路径长度，贪心选出最小值对应的点为新的前驱结点
        for (int j = 0; j < numV; ++j) {
//            未经造访 且 可达
            if (visited[j] == 0 && lowLR[j] < min) {
                min = lowLR[j];
                selectV = j;
            }
        }

//        更新访问过列表 selectv V-S -> S，作为下一轮的前驱结点使用
        visited[selectV] = 1;
    }
}

int main(){
//    n是定点个数
    int n,i,j,totalCost;
    //二维数组 邻接矩阵 E是定点 V是边的关系
    int cost[MaxV][MaxV];
    int ans[MaxV];

    while (EOF != scanf("%d",&n)){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <n; ++j) {
                scanf("%d",&cost[i][j]);
                if(cost[i][j] == -1)
                    cost[i][j]=INF;
            }
        }

        Dijkstra(cost,ans,n,0);

        totalCost = 0;

        for (int i = 0; i < n; ++i) {
            totalCost += ans[i];
        }

        printf("%d\n",totalCost);
    }
}