#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[100010];
int maxn = 0;
struct S{
    int a;
    int b;
}ss[100010];

void backtrack(int num,int nums){
    if(num == m){
        cout << nums << endl;
        maxn = max(nums,maxn);
        return;
    }

    if(nums + m - 1 - num  < maxn){
        return;
    }

    if(s[ss[num].a]==0 && s[ss[num].b]==0){
        s[ss[num].a]=1;
        s[ss[num].b]=1;
        cout << ss[num].a << ' ' << ss[num].b << ' ';
        backtrack(num+1,nums+1);
        s[ss[num].a]=0;
        s[ss[num].b]=0;
    }

    cout << endl;
    backtrack(num+1,nums);
}

int main(){
    cin >> n >> m;
    int dp[2][m+10][n+10];
    for(int i = 0;i < m; i++){
        cin >> ss[i].a >> ss[i].b;
    }

    memset(s,sizeof(s),0);
    backtrack(0,0);
    cout << m-maxn;

    int ssss;
    cin >> ssss;
    return 0;

}