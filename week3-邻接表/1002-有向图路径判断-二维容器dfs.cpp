/*
有向图路径存在判断
Description

给定一个有向图以及图的两个端点 v_i, v_jv 
i
​	
 ,v 
j
​	
 , 判断 v_iv 
i
​	
  到 v_jv 
j
​	
  是否存在路径.


Input
输入的第一行为 4 个正整数 n, m, s, t, 其中 n (n <= 100) 表示图的顶点个数(分别为从1 到 n), m (m <= 10000)表示有向图的边数, s 表示起点, t 表示终点

接下来 m 行, 每行有两个正整数 u, v, 表示点 u 到点 v 存在一条路径(有向).


Output
输出为单独的一行, 如果 s 到 t 存在路径, 输出 1, 否则输出 0.


Sample Input 1 

5 7 2 5
1 3
3 2
1 4
1 5
2 1
4 3
4 2
Sample Output 1

1
*/
#include<bits/stdc++.h>
using namespace std;
static const int MAX = 110;
static const int N = 10010;

vector<int>q[MAX];
int f[MAX];
int flag = 0;

void dfs(int u,int v)
{
    for(int i = 0;i < q[u].size(); i ++)
    {
        int j = q[u][i];
        if(flag)break;
        //printf("%d-%d\n",u,j);
        if(f[j] == 1)continue;
        //printf("%d--%d\n",u,j);
        if(j == v)flag = 1;
        else 
        {
            f[j] = 1;
            dfs(j,v);
        }
    }
}

int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;

    int u,v;

    memset(f,0,sizeof(f));
    for(int i = 0; i < m; i ++)
    {
        cin>>u>>v;
        q[u].push_back(v);
    }

    dfs(s,t);

    printf("%d",flag);

    return 0;   
}
