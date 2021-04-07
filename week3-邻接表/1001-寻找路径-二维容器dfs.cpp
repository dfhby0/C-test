/*
寻找路径
Description

给定一张包含N个点、N-1条边的无向连通图，节点从1到N编号，每条边的长度均为1。假设你从1号节点出发并打算遍历所有节点，那么总路程至少是多少？


Input
第一行包含一个整数 NN，1\leq N\leq 10^51≤N≤10 
5
 。

接下来 N-1N−1 行，每行包含两个整数 XX 和 YY，表示 XX 号节点和 YY 号节点之间有一条边，1\leq X, Y\leq N1≤X,Y≤N.


Output
输出总路程的最小值


Sample Input 1 

4
1 2
1 3
3 4
Sample Output 1

4
*/
#include<bits/stdc++.h>
using namespace std;

static const int N = 100100;

int f[N];
int maxd = 0;

vector<int>q[N];

void dfs(int x,int nmax)
{
    for(int i = 0; i < q[x].size();i ++)
    {
        int j = q[x][i];
        if(f[j]!=0)continue;
        f[j] = 1;
        maxd = max(maxd,nmax+1);
        //printf("%d-%d\n",j,maxd);
        dfs(j,nmax+1);
    }
}

int main()
{
    memset(f,0,sizeof(f));
    int u, v;
    int n;

    cin>>n;

    for(int i = 0; i < n - 1; i ++)
    {
        cin >> u >> v;
        q[u].push_back(v);
        q[v].push_back(u);
    }

    f[1] = 1;
    dfs(1,0);

    printf("%d",(n-1)*2-maxd);

    return 0;
}

