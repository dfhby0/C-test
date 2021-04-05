#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[71][35][71];
int t[71][71];

int main(){
    cin >> n >> m >> k;
    int num = m/2;
    memset(dp,sizeof(dp),0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m; j ++){
            cin >> t[i][j];
        }
    }

    dp[0][0][t[0][0] % k] = t[0][0];

    for(int j = 1;j < m;j++){
        for(int s = num-1;s >= 0;s--){
            for(int l = 0;l < k;l++){
                //cout << j <<' ' << s <<' '<<l <<endl;
                if(s==0){
                    //cout << dp[j-1][s][t[0][j] % k] << ' ' << dp[m-1][s][t[0][j] % k] <<  endl;
                    dp[j][s][t[0][j] % k] = max(dp[j-1][s][t[0][j] % k],dp[m-1][s][t[0][j] % k] + t[0][j]);
                    //cout << dp[j][s][t[0][j] % k] << endl;
                    continue;
                }
                if(dp[j-1][s-1][l]!=0){
                    int ss;
                    ss = dp[j-1][s-1][l] + t[0][j];
                    dp[j][s][ss%k] = max(ss,dp[j][s][ss%k]);
                    //cout << ss%k << ' ' << dp[j][s][ss%k] << endl;
                }
            }
        }
    }
    int maxn = 0;
    for(int i = num-1;i < m;i++){
        maxn = max(maxn,dp[i][num-1][0]);
    }
    cout << maxn;

    int ss;
    cin >> ss;

    return 0;

}

5 5 6
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5