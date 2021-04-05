#include<bits/stdc++.h>
using namespace std;
int n;
int nmap[21][21];
int maxn = 0;
int flag[21]={0};

void backtrack(int num,int dis,int total,int limit){
    if(total==limit){
        maxn = max(maxn,dis);
        return;
    }
    if(num==n){
        return;
    }
    for(int i = 0;i < n;i++){
        if(flag[i]==0){
            dis += nmap[num][i];
        }
    }
    for(int i = 0;i < num;i++){
        if(flag[i]==1){
            dis -= nmap[num][i];
        }
    }
    flag[num] = 1;
    backtrack(num+1,dis,total+1,limit);
    flag[num] = 0;
    for(int i = 0;i < n;i++){
        if(flag[i]==0){
            dis -= nmap[num][i];
        }
    }
    for(int i = 0;i < num;i++){
        if(flag[i]==1){
            dis += nmap[num][i];
        }
    }
    backtrack(num+1,dis,total,limit);
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j ++){
            cin >> nmap[i][j];
        }
    }
    for(int i = 1;i <= n/2;i++)
        backtrack(0,0,0,i);
    cout << maxn;
    return 0;
}