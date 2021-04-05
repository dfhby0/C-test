#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[110],w[110];
int maxn = -1;
int t[110];
int b[110];
int total = 0;

void dfs(int x,int curweight,int curvalue,int nextmax){
    
    cout << x <<' ' <<curweight<<' ' <<curvalue<<' ' <<nextmax << endl;
    if(curvalue > maxn && curvalue!= 0 && curvalue%curweight == 0 && curvalue/curweight == m){
        cout << x <<' ' <<curweight<<' ' <<curvalue<<' ' <<nextmax << endl;
        maxn = curvalue;
        for(int i = 1;i <= n;i ++)b[i] = t[i];
    }
    if(x == n + 1)return;
    if(nextmax + curvalue < maxn) return;
    t[x] = 1;
    dfs(x+1,curweight + w[x],curvalue+v[x],nextmax-v[x]);
    t[x] = 0;
    dfs(x+1,curweight,curvalue,nextmax);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> v[i];
        total += v[i];
    }   
    
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    
    dfs(1,0,0,total);
    
    cout << maxn;

    int ss;
    cin >> ss;

    return 0;
}