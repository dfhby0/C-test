#include<iostream>
#include<math.h>
using namespace std;

const int N = 100010;
int t[N],val[N],n;
int maxn = 0;

int dfs(int j)
{
    int maxd;
    if(t[j]==0)return 0;
    
    maxd = val[j] + max(dfs(j*2),dfs(j*2+1),0);
    maxn = max(maxd,maxn);
    return maxd;
}

int main()
{
    t[1] = 1;
    scanf("%d",&n);
    for(int i = 1; i < n + 1; i ++) scanf("%d%d%d",&t[i*2],&t[i*2+1],&val[i]);

    dfs(1);

    printf("%d",maxn);

    return 0;
}



