/*
距离产生美
Description

Alice 和 Bob 率先登上了火星, 二人决定以火星上的山丘为中心开辟各自的领地,

为了和平发展, 互不影响, 二人决定把火星上现有的山丘分成两组, 每人获得其中的一组, 要求不同组的任意两个山丘之间的距离之和最大.

求最大的距离和.


Input
输入的第一行为一个正整数 n \in [2,20]n∈[2,20], 表示火星上所有山丘的总数.

接下来 nn 行, 每行包含 nn 个整数, 构成一个矩阵 DD, D_{ij}D 
ij
​	
  表示山丘 ii 和 jj 之间的距离.


Output
输出单独一行, 表示两组山丘之间距离和的最大值.


Sample Input 1 

4
0 20 30 50
20 0 50 15
30 50 0 20
50 15 20 0
Sample Output 1

145
*/

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