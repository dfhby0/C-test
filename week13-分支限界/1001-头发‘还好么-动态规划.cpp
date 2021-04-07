/*
你的头发还好吗？
Description

Alice 备战 ICPC 竞赛, 现有 nn 道练习题, Alice 解出一道题可以获得对应的能力值提升, 但需要消耗一定数量的头发.

为了保住 Alice 的头发,需要满足能力提升的总和是消耗头发数量的mm倍, 在满足上述要求的前提下, 请问 Alice 最多能提升的能力值为多少?


Input
输入包含 33 行,

第一行为两个正整数 n\in [1,100], m\in [1,10]n∈[1,100],m∈[1,10], 用空格隔开,

第二行为 nn 个正整数 x_1, x_2, \cdots, x_n \in [1,100]x 
1
​	
 ,x 
2
​	
 ,⋯,x 
n
​	
 ∈[1,100], 表示解决每道题可以获得的能力值，

第三行为 nn 个正整数 y_1, y_2, \cdots, y_n \in [1,100]y 
1
​	
 ,y 
2
​	
 ,⋯,y 
n
​	
 ∈[1,100], 表示解决每道题消耗的头发数量.


Output
输出满足条件情况下 Alice 可以获得的最大能力值, 如果没有满足条件的解, 输出 -1−1.


Sample Input 1 

2 1
75 65
16 60
Sample Output 1

-1
Sample Input 2 

3 2
10 8 1
2 7 1
Sample Output 2

18
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

    //int ss;
    //cin >> ss;
    return 0;
    

}*/
