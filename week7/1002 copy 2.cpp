#include<bits/stdc++.h>
using namespace std;

const int INF = 0;
int n;
struct B{
    int v;
    int q;
    int r;
    int sign;
}b[110];

bool cmp(const B &x,const B &y)
{
    return x.v < y.v;
}

int main(){
    scanf("%d",&n);
    int maxn = 0;
    for(int i = 0;i < n; i ++){
        cin >> b[i].q;
    }

    int total_v1 = 0;
    for(int i = 0;i < n; i ++){
        cin >> b[i].v;
        total_v1 = total_v1 + b[i].v;
        b[i].r = b[i].v - b[i].q;
        maxn = maxn + b[i].q;
    }
    
    sort(b,b+n,cmp);

    if(n<=1){
        printf("%d %d",1,0);
        return 0;
    }

    int total_v = 0;
    int flag,min_num=0,max_num=0;
    for(int i = n-1; i >= 0;i --){
        total_v = total_v + b[i].v;
        b[i].sign = 1;
        min_num++;
        max_num++;
        if(total_v >= maxn){
            flag = i;
            break;
        }
    }
    
    int resn = total_v1 - maxn;
    int dp[110][resn+10];

    for (int t = 1 ; t <= n ; t ++) 
        for (int j = resn ; j >=b[t].v; j --){
            dp[]

    for (int t = 1 ; t <= n ; t ++) 
        for (int i = n-min_num ; i >= 1 ; i --) 
            for (int j = resn ; j >=b[t].v; j --){
                dp[i][j] = min(dp[i][j], dp[i-1][j - b[t].v] - b[t].q);
            }

    int minn = 10000000;
    for(int j = 0; j <= resn; j ++)
        minn = min(minn, dp[1][j]);
    
    cout << min_num <<' '<< minn<<endl;

    int sss;
    cin >> sss;

    return 0;

}


