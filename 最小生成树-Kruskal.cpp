//
// Created by 岳晨阳 on 2019/12/14.
//
//并查集

#include <algorithm>
#define MaxV 100
#define MaxE 1000
struct edge {
    int x, y;
    int w;
};
struct node {
    int father;   //father为节点所在树的树根
    int height;   //height为秩
};
node juSet[MaxV];  //树根的集合；初始状态下各节点是自身的树根

// 比较函数，按权值(相同则按边的第一个顶点)非降序排序
int cmp(const void *a, const void *b) {
    if ((*(struct edge *) a).w == (*(struct edge *) b).w) {
        return (*(struct edge *) a).x - (*(struct edge *) b).x;   //*a等于*b时，即边的权重相等时，再按边的第一个顶点X来排序
    }
    return (*(struct edge *) a).w - (*(struct edge *) b).w;
}

// 查找x元素所在的树的树根；初始状态下x元素所在树的树根就是自身；
int Find_Set(int x) {
    while (x != juSet[x].father) {
        x = juSet[x].father;
    }
    return x;
}

// 合并x,y所在的集合
void Union(int x, int y) {
    if (x == y)
        return;
    if (juSet[x].height > juSet[y].height)//将秩较小的树上的节点y连接到秩较大的树上的节点x上，无论x是否是树根；
        juSet[y].father = x;
    else {
        if (juSet[x].height == juSet[y].height)
            juSet[y].height++;
        juSet[x].father = y;
    }
}

int kruskal(node juSet[MaxV],int numV,edge edgeSet[MaxE],int numE) {
    qsort(edgeSet, numE, sizeof(struct edge), cmp);//将边集合edgeSet中的元素按权重排序
    int totalCost = 0, cntE = 0, fatherX, fatherY;
    for (int i = 0; i < numE; i++) {//遍历每一条边
        fatherX = Find_Set(edgeSet[i].x);
        fatherY = Find_Set(edgeSet[i].y);
        if (fatherX != fatherY) {
            Union(fatherX, fatherY);
            totalCost += edgeSet[i].w;
            cntE++;
        }
        //如果加入边的数量小于点的数目减1,则表明存在孤立节点，该无向图不连通,即不存在最小生成树
        if (numE < numV - 1)
            totalCost = -1; 

        return totalCost;
    }
}
