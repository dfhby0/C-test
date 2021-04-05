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
        printf("%d-%d\n",u,j);
        if(f[j] == 1)continue;
        printf("%d--%d\n",u,j);
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