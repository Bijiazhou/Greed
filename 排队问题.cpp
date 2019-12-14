//
// Created by 岳晨阳 on 2019/12/14.
//

//问题描述： 在一个医院B 超室，有n个人要做不同身体部位的B超，已知每个人需要处理的时间为ti，（0<i<=n），请求出一种排列次序，使每个人就医时间总和最小。
//输入：多组测试数据，每组测试数据包含两行：第一行输入B超检查人数n（n <=100000），第二行输入n个不超过 1000的正整数ti，表示每个人需要的处理时间。
//输出：n个人排队时间最小总和，一组测试数据输出一行。
//输入样例
//4
//5 10 8 7
//输出样例
//67

//分析
//大家的排队时长最短 那么就需要
#include <stdio.h>
#include <algorithm>
#define MaxTime 1000

int queue_op(int n, int pInt[1000]);
int operate[MaxTime];

int main (){
    int n = 0;
    int totaltime = 0;
//    while (scanf("%d",&n)!= EOF){
    scanf("%d",&n);
    printf("%d",n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d",&operate[i]);
    }
    totaltime = queue_op(n,operate);
    printf("%d",totaltime);
//    }
}

int queue_op(int n, int operate[MaxTime]) {
    int min = 0;

    std::sort(operate,operate+n+1);
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ",operate[i]);
//    }

    for (int i = 1; i <= n; ++i) {
        min += (operate[i]*(n-i) + operate[i]);
    }

    return min;
}
