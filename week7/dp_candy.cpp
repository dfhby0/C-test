#include<bits/stdc++.h>
'''
    主要思路是找到相关联的项，这里只有前三项会影响后面

    数据过长，使用unsigned long long重新定义
'''
using namespace std;
const int N=100010;
int q[N],p[N];
int s[N];
int n;


int main(){
    scanf("%d",&n);
    memset(s,sizeof(s),0);
    int maxn=0;
    for(int i = 0; i < n; i ++){
        scanf("%d",&q[i]);
        s[q[i]]++;
        if(q[i]>maxn)
            maxn = q[i];
    }
    p[1] = s[1] * 1;
    p[2] = max(s[2] * 2,p[1]);
    p[3] = max(s[3] * 3 + p[1], p[2]);
    for(int i = 4; i < maxn + 1; i ++){
        p[i] = max(p[i-2] + s[i] * i,max(p[i-3] + s[i-1]*(i-1),p[i-1]));
    }

    printf("%d",p[maxn]);

    return 0;
}

