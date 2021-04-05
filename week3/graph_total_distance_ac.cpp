#include<bits/stdc++.h>
using namespace std;

static const int N = 10010;

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
