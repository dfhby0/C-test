/*
简单加法
Description

给定一个 n\times mn×m 的矩阵, 你最多可以从每行选择不超过一半的元素, 使得他们的和在可以被目标值 kk 整除的情况下最大.


Input
第一行包含三个正整数 n, m, k \in [1,70]n,m,k∈[1,70], 分别表示矩阵的行数, 列数以及目标值,

后续 nn 行, 每行 mm 个元素, 表示要输入的矩阵. 其中每个元素的值 a_{i,j} \in [1,70]a 
i,j
​	
 ∈[1,70].


Output
输出可以被 kk 整除的最大的和.


Sample Input 1 

3 4 10
3 3 3 3
3 6 8 5
3 8 8 5
Sample Output 1

30
Sample Input 2 

3 3 8
2 5 1
1 7 1
2 2 3
Sample Output 2

8
*/
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

    // int ssss;
    // cin>>ssss;

    return 0;
}