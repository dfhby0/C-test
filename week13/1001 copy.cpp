#include<bits/stdc++.h>
using namespace std; 
int x[110],y[110];
int n,m;
double dp[110][11000 * 2];


int main()
{   
    
    cin>>n>>m;
    int total = 0;
    memset(dp,sizeof(dp),0);
    for(int i = 0 ; i < n ; i ++){
        cin>>x[i];
        total += x[i];
    }    
    for(int i = 0 ; i < n ; i ++)
        cin>>y[i];

    for(int i = 0;i<n;i++){
        dp[i][x[i]-m*y[i] + total] = x[i];
    }
    for(int i = 1; i < n;i ++){
        for(int j =0;j < 2*total;j++){
            if((j - x[i] + m*y[i]) >= 0 && j - x[i] + m*y[i] < 2*total && dp[i-1][j-x[i]+m*y[i]]!=0){
                //cout << j-total << ' ' << dp[i-1][j] << ' ' << dp[i-1][j-x[i]+m*y[i]] << ' ' << j-x[i]+m*y[i] << ' ' << endl;
                dp[i][j] = max(max(dp[i][j],dp[i-1][j]),dp[i-1][j-x[i]+m*y[i]]+x[i]);
                //cout << j << ' ' << dp[i][j]<<endl;
            }
            else{
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
    }

    if(dp[n-1][total] == 0)dp[n-1][total] = -1;
    cout << dp[n-1][total];

    int ss;
    cin >> ss;
    return 0;
    

}