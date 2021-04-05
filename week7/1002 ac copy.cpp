#include<bits/stdc++.h>
using namespace std;

//   主要思路是将原本问题转化为一个二维背包问题，
//   从被转移的油漆桶出发，条件如下：
//   1、总共被转移的油漆桶数不超过（应为）n-min_num，其中min_num是最要的桶的最小数量，可较容易找出，
//   2、总共被转移油漆数不超过resn，其中resn为最大可剔除容积=总容积-剩余体积
//   dp[i][j][m] = min(dp[i-1][j][m],dp[i-1][j-b[i].v][m-1] + b[i].q);

const int INF = 1000000;
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
    int dp[resn+10][n-min_num+10];

    for(int j = resn; j >= 0; j --)
        if(j>=b[0].v)
            dp[j][1] = b[0].q;
        else
            dp[j][1] = INF;
    
    for(int j = resn; j >= 0; j --)
        dp[j][0] = 0;

    for(int m = 2; m <= n-min_num;m++)
        for(int j = resn; j >= 0; j --){
            dp[j][m] = INF;
        }
            

    for(int i = 1; i < n; i ++){
        for(int m = n-min_num; m >=1 ; m --){    
            for(int j = resn; j >= b[i].v; j --){
                dp[j][m] = min(dp[j][m],dp[j-b[i].v][m-1] + b[i].q);
            }
        }
    }
    int minn = 10000000;
    for(int j = 0; j <= resn; j ++)
        minn = min(minn,dp[j][n-min_num]);
    cout << min_num <<' '<< minn<<endl;
    int sss;
    cin >> sss;

    return 0;

}


