#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[110],w[110];
int maxn = -1;
int t[110];
int b[110];
int total = 0;

struct node{
	int v;
	int w;
}vw[110];

bool cmp(node a,node b){
	return a.v < b.v;
}

void dfs(int x,int curweight,int curvalue,int nextmax){
    
    //cout << x <<' ' <<curweight<<' ' <<curvalue<<' ' <<nextmax << endl;
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

void dfs1(int )


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        cin >> vw[i].v;
        total += vw[i].v;
    }   
    
    for(int i = 0; i < n; i ++){
        cin >> vw[i].w;
    }
    
    sort(vw,vw+n,cmp);

    for(int i = m;i < total ;i ++){
        if(i%m == 0){
            dfs(1,0,0,total);
        }
    }
    
    
    cout << maxn;

    int ss;
    cin >> ss;

    return 0;
}