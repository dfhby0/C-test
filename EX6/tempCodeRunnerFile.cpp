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
    if(m==1){
        cout << 0;
        return 0;
    }

    for(int i = 0;i < n; i ++){
        for(int l = 0;l < k;l++){
            int ss1 = dp[m-1][num][l] + t[i][0];
            dp[0][0][ss1%k] = max(ss1,dp[0][num][ss1%k]);
            //cout << dp[m-1][num][l] << ' ' << t[i][0] << ' ' << ss1%k<<endl;
        }
        for(int j = 1;j < m;j++){
            for(int s = num-1;s >= 0;s--){
                if(s==0){
                    for(int l = 0;l < k;l++){
                        int ss1 = dp[m-1][num][l] + t[i][j];
                        //cout << dp[m-1][num][l] << ' ' << t[i][j] << ' '<< ss1  << endl;
                        dp[j][0][ss1%k] = max(ss1,dp[j-1][0][ss1%k]);
                        dp[j][s][l] = max(dp[j][s][l],dp[j-1][s][l]);
                    }
                    continue;
                }
                for(int l = 0;l < k;l++){
                    dp[j][s][l] = max(dp[j][s][l],dp[j-1][s][l]);
                    //cout << j <<' ' << s <<' '<<l <<' ' << dp[j][s][l] << ' ' << dp[j-1][s][l] <<endl;
                    if(dp[j-1][s-1][l]!=0){
                        int ss;
                        ss = dp[j-1][s-1][l] + t[i][j];
                        dp[j][s][ss%k] = max(ss,dp[j][s][ss%k]);
                        //cout << ss%k << ' ' << dp[j][s][ss%k] << endl;
                    }
                }
            }
        }
        for(int l = 0;l < k;l++){
            for(int j = 0;j < m;j++){
                for(int s = num-1;s >= 0;s--){
                    dp[m-1][num][l] = max(dp[m-1][num][l],dp[j][s][l]);
                }
            }
        }
        // for(int l = 0;l < k;l++){
        //     cout << dp[m-1][num][l] << ' '; 
        // }
        // cout << endl;
        
    }
    int maxn = 0;
    for(int i = num-1;i < m;i++){
        //cout << dp[i][num][0] << endl;
        maxn = max(maxn,dp[i][num][0]);
    }
    cout << maxn;

    int ssss;
    cin>>ssss;

    return 0;
}
