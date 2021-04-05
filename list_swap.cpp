#include<iostream>
using namespace std;

const int N = 100010;
int idx,n,m,head;
int e[N],ne[N];

void init()
{
    head = -1;
    idx = 0;
}

void add_tohead(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

int main()
{
    scanf("%d%d",&n,&m);
    init();
    for (int i = 0;i < n;i ++)
    {
        int v;
        scanf("%d",&v);
        if(i==0)add_tohead(v);
        else add(i,v);
    }

    int num = m % n;

    for (int i = 0;i < n;i ++)
    {
        if (i < num) printf("%d ",e[n - num + i]);
        else printf("%d ",e[i - num]);
    }

    return 0;
}