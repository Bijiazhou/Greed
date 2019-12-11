//
// Created by 岳晨阳 on 2019/12/10.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
int greedyEventSchedule(int n, int *timeStart,int *timeFinish){
    int i,j,selected,ans = 0;
    //冒泡排序 使得活动案结束时间升序排列

    for(i=0;i<n;i++)
        for(j=0;j+1<n;j++)
            if(timeFinish[j]<timeStart[j+1]){
                swap(timeFinish[j],timeFinish[j+1]);
                swap(timeStart[j],timeStart[j+1]);
            }

    selected = 0;
    ans = 1;
    for(i = 1; i<n; i++){
        if(timeStart[i] >= timeFinish[selected]){
            selected = i;
            ans ++;
        }
    }
    return ans;
}
int main(){
    int i,n,ans,s[1000],f[1000];

    while (scanf("%d",&n) != EOF){
        for (int i = 0; i < n ; ++i) {
            scanf("%d",&s[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d",&f[i]);
        }

        ans = greedyEventSchedule(n,s,f);
        printf("%d",ans);
    }
    return 0;
}
