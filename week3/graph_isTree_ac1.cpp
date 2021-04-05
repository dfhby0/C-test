#include<bits/stdc++.h>
using namespace std;
static const int N = 100010;

unordered_map<int,queue<int>>que;
int M[N];
int num = 0;
int test_num = 0;
int edge = 0;

void dfs(int a)
{
    int b;
    while(!que[a].empty())
    {
        M[a] = 1;
        if(!M[que[a].front()])
        {
            edge ++;
            b = que[a].front();
            //printf("%d-%d ",a,b);
            que[a].pop();
            dfs(b);
        }
        else
        {
            que[a].pop();
        }
    }
}

int main()
{
    memset(M,0,sizeof(M));
    int n;
    int a,b;
    int oa,ob;
    scanf("%d",&n);
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        scanf("%d%d",&a,&b);
        if(que[a].size()==0)num++;
        if(que[b].size()==0)num++;
        que[a].push(b);
        que[b].push(a);
    }
    
    dfs(a);

    for(int i = 0;i<N;i++)
    {
        if(M[i]!=0)test_num++;
    }
    if(edge==n&&test_num==num)printf("YES");
    else printf("NO");

    return 0;
}