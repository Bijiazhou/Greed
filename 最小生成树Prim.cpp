//
// Created by 岳晨阳 on 2019/12/14.
//
#define MaxV 1000
#define INF 0x03f3f3f3f

int prim(int linkMatrix[][MaxV],int numV){
    int visited[MaxV] = {0};// 是否加入MST
    int lowCost[MaxV],closest[MaxV];
    int i,k;
    int min,costMST = 0;

//    顶点加入MST的U中
    visited[0] = 1;
//    树根的标记
    closest[0] = 1;
//    将V-U中每个点到树根的跨边值都初始化为这些点的最小跨边值
    for (int i = 0; i < numV; ++i) {
        lowCost[i] = linkMatrix[0][i];
        closest[i] = 0;
    }

    for (int i = 0; i < numV-1; ++i) {
        min = INF;
        int selectV = 0;
        //    从U-V集合中个点对应的、最新的的最小跨边值中选择最小的那个跨边值
        for (int k = 0; k < numV; ++k) {
            if(!visited[k] && lowCost[k] < min){
                min = lowCost[k];
                selectV = k;
            }
        }

        costMST += min;
        visited[selectV] = 1;

        for (int k = 0; k < numV; ++k) {
            if (!visited[k] && linkMatrix[selectV][k] < lowCost[k]){
                lowCost[k] = linkMatrix[selectV][k];
                closest[k] = selectV;
            }
        }
    }
    return costMST;
}