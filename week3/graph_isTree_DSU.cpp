#include<bits/stdc++.h>
using namespace std;
static const int N = 100010;

int M[N];
int num = 0;
int test_num = 0;
int edge = 0;
int pre[1005];

static int findhead(unordered_map<int,int>&que, int x)
{
    int k = x;
    if(que.find(x)==que.end())
    {
        que[x] = x;
        return x;
    }

    //路径压缩
    while(que[k]!=k)k = que[k];
        
    while(que[x]!=x)
    {
        int cur=que[x];
        que[x] = k;
        x = cur;
    }

    return k;
}

int main()
{
    
    unordered_map<int,int>que;
    int n;
    int a,b;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d%d",&a,&b);
        int head1 = findhead(que,a);
        int head2 = findhead(que,b);
        if(head1==head2)
        {
            printf("NO");
            return 0;
        }
        que[head1] = head2;
    }
    
    printf("YES");

    return 0;
}