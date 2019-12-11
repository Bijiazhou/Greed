//
// Created by 岳晨阳 on 2019/12/11.
//

#include<iostream>
#include <algorithm>

using namespace std;

int num_in();
int num_out();
int sort_me();
int a[10];

int main()
{
//    输入数字
    num_in();

//    排序
    sort_me();

//    输出
    num_out();

}


int num_in()
{	int i;
    cout<<"请输入十个数字："<<endl;
    for(i=0;i<10;i++)
    {
        cout<<"请输入第"<<i<<"个字"<<endl;
        cin>>a[i];
    }
}

int sort_me()
{	int n,i,k;

    for(k=0;k<9;k++)
        for(i=0;i<9-k;i++)
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
//                n=a[i+1];
//                a[i+1]=a[i];
//                a[i]=n;
            }
}


int num_out()
{
    cout<<"由小到大的排列顺序为： ";
    int i;
    for(i=0;i<10;i++)
        cout<<a[i]<<"  ";
}


