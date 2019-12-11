//
// Created by 岳晨阳 on 2019/12/11.
//
//问题描述：给定𝑛种物品和一个背包。物品𝑖的重量是𝑊𝑖，其价值为𝑉𝑖，背包的容量为C，应如何选择装入背包的物品使得装入背包中物品的总价值最大?
// 这里，在选择物品𝑖装入背包时，可以选择物品𝑖的一部分，而不一定要全部装入背包。(所以称为小数，而不是0-1选择)
//
//输入：多组测试数据。每组测试包括三行：第一行输入物品的总数𝑛(𝑛<1000）和背包的容量𝐶(𝐶<1000)。第二行输入𝑛个整数，表示物品的重量。第三行输入物品的价值。
//输出：输出装入背包的总价值，每组测试数据输出一行。
//
//输入样例：
//3  50
//10  20   30
//100  120
//
//输出样例：
//240

#include <stdio.h>
#include <algorithm>

using namespace std;
#define MaxItems 1000

struct item{
    int weight;
    int value;
    //学到了 结构体内嵌比较函数 从大到小排列
    bool operator<(const item& bb)const {
        return value/(1.0*weight) > (1.0 *bb.value)/bb.weight;
    }
};

double greedKnapsack(int n,int capacity,item *itemSet){
    double ans = 0;

    //排序
    sort(itemSet,itemSet+n);

    for(int i = 0;i<n;i++){
        if(capacity >= itemSet[i].weight){
            ans += itemSet[i].value;
            capacity -= itemSet[i].weight;
        } else{
            ans += capacity*(itemSet[i].value/itemSet[i].weight);
            break;
        }
    }
    return ans;
}

int main(){
    int i,n,c;
    item itemSet[1000];

    double ans;

    while (scanf("%d%d",&n,&c)!=EOF){
        for (int i = 0; i < n ; ++i) {
            scanf("%d",&itemSet[i].weight);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d",&itemSet[i].value);
        }
        ans = greedKnapsack(n,c,itemSet);
        printf("%.0f\n",ans);
    }
    return 0;
}