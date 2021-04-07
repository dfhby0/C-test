/*
吃辣条大赛
Description

Alice 参加了学院近期举办的吃辣条大赛, 桌子上摆放了若干根辣条, 每根辣条的长度不等, 要求只能按从左到右长度严格递增的顺序吃, 每位参赛选手有一次机会扔掉其中的一根辣条(也可以不扔).

给出从左到右排列的每根辣条的长度, 请问 Alice 最多可以吃到多少根辣条.


Input
输入包含两行, 第一行为一个正整数 n \in [2, 200000]n∈[2,200000], 表示辣条的总数.

第二行为 nn 个正整数 l_1, \cdots , l_nl 
1
​	
 ,⋯,l 
n
​	
 , 用空格分隔, 表示每根辣条的长度 l_i \in [1,10^9]l 
i
​	
 ∈[1,10 
9
 ].


Output
输出单独一行, 表示 Alice 能吃到的辣条的最大数量.


Sample Input 1 

6
2 3 8 4 5 7
Sample Output 1

5
Hint

在测试样例中, 可以扔掉第三根辣条, 得到 `2 3 4 5 7`, 因此最终可以吃到 5 根.
*/

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