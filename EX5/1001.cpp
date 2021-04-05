#include<bits/stdc++.h>
using namespace std;

int n;
int t[110],d[110],v[110];

struct R{
    int t;
    int d;
    int v;
    int time;
}r[110];

bool cmp( R &a,R &b){
    return a.time < b.time;
}

int maxn = 0;
int rest[110];
void dfs(int num,int t,int v){
    if(num==n){
        maxn = max(maxn,v);
        return;
    }

    if(v + rest[num] < maxn)return;
    if(t < r[num].time)
        dfs(num+1,t+r[num].t,v+r[num].v);
    
    dfs(num+1,t,v);
}

int main(){
    cin >> n;
    for(int i = 0; i < n ;i ++){
        cin >> r[i].t >> r[i].d >> r[i].v;
        r[i].time = r[i].d-r[i].t;
    }

    sort(r,r+n,cmp);

    rest[n-1] = r[n-1].v;
    for(int i = n-2;i >= 0;i--){
        rest[i] = rest[i+1] + r[i].v; 
    }

    dfs(0,0,0);

    cout << maxn;

    return 0;

}
