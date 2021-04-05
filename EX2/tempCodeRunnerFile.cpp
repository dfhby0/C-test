#include<bits/stdc++.h>
using namespace std;
const int N = 100020;
unsigned long long dp[2][2][N];

int main(){
    int n;
    unsigned long long l1[N],l2[N];
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        cin >> l1[i];
    }
    for(int i = 0; i < n; i ++){
        cin >> l2[i];
    }
    dp[0][1][0] = l1[0];
    dp[1][1][0] = l2[0];
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    if(n<2){
        cout<< max(l1[0],l2[0]);
        return 0;
    }
    dp[0][1][1] = l2[0] + l1[1];
    dp[1][1][1] = l2[1] + l1[0];
    dp[0][0][1] = l2[0];
    dp[1][0][1] = l1[0];

    unsigned long long maxn = max(l2[0] + l1[1],l2[1] + l1[0]);
    
    for(int i = 2; i < n; i ++){
      dp[0][0][i] = max(dp[1][1][i-1],max(dp[1][0][i-1],max(dp[0][1][i-2],dp[0][0][i-2])));
      dp[1][0][i] = max(dp[0][1][i-1],max(dp[0][0][i-1],max(dp[1][1][i-2],dp[1][0][i-2])));
      dp[0][1][i] = max(dp[1][1][i-1],max(dp[1][1][i-2],max(dp[1][0][i-2],max(dp[0][1][i-2],dp[0][0][i-2])))) + l1[i];
      dp[1][1][i] = max(dp[0][1][i-1],max(dp[0][1][i-2],max(dp[1][1][i-2],max(dp[0][0][i-2],dp[1][0][i-2])))) + l2[i];
      cout << dp[0][0][i]  << ' '<<dp[1][0][i] << ' ' <<dp[0][1][i] <<  ' '<< dp[0][1][i]<<endl;
      maxn = max(dp[0][0][i],max(dp[1][0][i],max(dp[0][1][i],max(dp[1][1][i],maxn))));
    }

    cout << maxn;
    return 0;
}