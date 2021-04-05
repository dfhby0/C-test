
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ss[410];
struct S{
    int s;
    int d;
    long long c;
    int r;
}car[300000];
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> ss[i];
    }
    long long maxn=0;
    for(int i = 0;i < m;i++){
        cin >> car[i].s >> car[i].d >> car[i].c >> car[i].r;
        //对每个运输车求：（终点距离-起点距离）*每公里油耗/（补给次数+1），然后取最大的值
        long long t = (ss[car[i].d] - ss[car[i].s])*car[i].c/(car[i].r + 1);
        maxn = max(t,maxn);
    }
    cout << maxn;
    return 0;
}