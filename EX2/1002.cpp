#include<bits/stdc++.h>
using namespace std;
const int N = 200020;
int dp[2][N];

int main(){
    int n;
    long long l[N];
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        cin >> l[i];
    }
    dp[0][0] = 1;
    dp[1][0] = 0;
    int maxn = 1;
    if(l[1] > l[0]){
        dp[0][1] = 2;
        maxn = 2;
    }
    else
        dp[0][1] = 1;
    dp[1][1] = 1;
    
    for(int i = 2; i < n; i ++){
        for(int j = 0; j < 2; j++){
            int a = 0, b = 0, c = 0, d = 0;
            if(l[i] > l[i-1]){
                a = dp[0][i-1] + 1;
                d = dp[1][i-1] + 1;
            }
            if(l[i] > l[i-2]){
                c = dp[0][i-2] + 1;
            }
            dp[0][i] = max(a,1);
            dp[1][i] = max(c,d);
            maxn = max(dp[0][i],max(dp[1][i],maxn));
        }
    }

    printf("%d",maxn);
    return 0;
}