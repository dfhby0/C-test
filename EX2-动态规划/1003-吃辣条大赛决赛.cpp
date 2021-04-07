/*
吃辣条大赛决赛
Description

Alice 进入了吃辣条大赛的决赛, 决赛的规则如下:

桌子上从左到右摆放了两排辣条, 每一排辣条的数量均为 nn,每根辣条的长度不等.
每个人可以从任意一根辣条开始吃, 但是不能连续吃同一排的辣条, 吃的顺序必须严格从左到右(即吃了第 11 排的第 ii 根, 则不能继续吃 第 22 排的第 ii 根, 只能从第 i+1i+1 根往右吃).
吃到的辣条总长度最长的人获胜.
求 Alice 能吃到的辣条的最大总长度.


Input
输入包含三行,

第一行为一个正整数 n \in [1,100000]n∈[1,100000], 表示每一排辣条的数量.

第二行为 nn 个正整数 a_1, \cdots, a_n \in [1, 10^9]a 
1
​	
 ,⋯,a 
n
​	
 ∈[1,10 
9
 ],用空格隔开,从左到右表示第一排每根辣条的长度；第三行为 nn 个正整数 b_1, \cdots, b_n\in [1, 10^9]b 
1
​	
 ,⋯,b 
n
​	
 ∈[1,10 
9
 ], 用空格隔开, 从左到右表示第二排每根辣条的长度.


Output
输出 Alice 能吃到的辣条总长度的最大值.


Sample Input 1 

3
1 2 9
10 1 1
Sample Output 1

19
*/
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
      dp[0][0][i] = max(dp[1][1][i-1],max(dp[1][0][i-1],max(dp[1][1][i-2],max(dp[1][0][i-2],max(dp[0][1][i-2],dp[0][0][i-2])))));
      dp[1][0][i] = max(dp[0][1][i-1],max(dp[0][0][i-1],max(dp[1][1][i-2],max(dp[1][0][i-2],max(dp[0][1][i-2],dp[0][0][i-2])))));
      dp[0][1][i] = max(dp[1][1][i-1],max(dp[1][1][i-2],max(dp[1][0][i-2],max(dp[0][1][i-2],dp[0][0][i-2])))) + l1[i];
      dp[1][1][i] = max(dp[0][1][i-1],max(dp[0][1][i-2],max(dp[1][1][i-2],max(dp[0][0][i-2],dp[1][0][i-2])))) + l2[i];
      //cout << dp[0][0][i]  << ' '<<dp[1][0][i] << ' ' <<dp[0][1][i] <<  ' '<< dp[0][1][i]<<endl;
      maxn = max(dp[0][0][i],max(dp[1][0][i],max(dp[0][1][i],max(dp[1][1][i],maxn))));
    }

    cout << maxn;
    return 0;
}