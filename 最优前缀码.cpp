//
// Created by 岳晨阳 on 2019/12/11.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define MaxChar 1000
using namespace std;

struct cmp{
    bool operator()(const int &x, const int &y){
        return x>y;
    }
};//定义优先队列需要的比较函数

double haffmanCoding(int n,int * freq){
    int i,total = 0 ,sumFreq = 0,jointFreq;

    priority_queue<int ,vector<int>,cmp>heap;//优先队列 最小值优先

    for (int i = 0; i < n; ++i) {
        total += freq[i]; //频次的和
        heap.push(freq[i]);
    }//形成优先队列

    while (heap.size()>1){
        jointFreq = 0;//合并后节点的频次

        for (int i = 0; i < 2; ++i) {
            jointFreq += heap.top();
            heap.pop();//弹出两个最小的节点
        }
        sumFreq += jointFreq;
        heap.push(jointFreq);//插入合并后的节点
    }
    return sumFreq/(1.0 * total);
}

int main(){
    int n,i,freq[MaxChar];

    while (scanf("%d",&n)!=EOF){
        for (int i = 0; i < n; ++i) {
            scanf("%d",freq + i);
        }
        double codeLength = haffmanCoding(n,freq);
        printf("%.4f\n",codeLength);
    }
}