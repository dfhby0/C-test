#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int main(){
    int n,r;
    scanf("%d %d",&n,&r);

    int c[N],s[N];
    for(int i = 0; i < n; i++)
        scanf("%d",&c[i]);
    for(int i = 0; i < n; i++)
        scanf("%d",&s[i]);

    int dp[N];
    for(int i = r; i > 0; i--)dp[i] = 0;
    for(int j = 0; j < n; j ++){
        for(int i = r; i >= s[j]; i--){
            dp[i] = max(dp[i],dp[i-s[j]]+c[j]);
        } 
    }
    int maxn = 0;
    for(int i = r; i >= 0; i --){
        //cout << n<<' ' << r<< ' ' << dp[i] <<' ';
        maxn = max(dp[i],maxn);
    }
    printf("%d",maxn);
    return 0;
}