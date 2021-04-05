#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
const int maxn = 1e6 + 10;

vector<P>v;
int a[maxn];
int e[maxn],ne[maxn];

int main()
{
    int n,x;
    int idx = 0;
    int head = -1;
    bool flag = false;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d",&x);
        if(i==0)
        {
            idx ++;
            head ++;
            ne[head] = -1;
            e[head] = x;
        }
        else
        {   
            ne[idx-1] = idx;
            ne[idx] = -1;
            e[idx] = x;
            idx ++; 
        }
    }
    for(int i=head;i!=-1;i=ne[i])v.push_back({e[i],i});
    sort(v.begin(),v.end());
    n = (int)v.size();
    for (int i = 0;i < n;i ++)
    {
        printf("%d ",v[i].first);
    }

    return 0;
}