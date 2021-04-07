/*
魔兽争霸
Description

魔兽争霸游戏中, 不同的建筑可以生产不同的兵种, 不同建筑的价值不同, 玩家可以指挥兵力攻击敌人的建筑, 建筑全部被摧毁的一方游戏失败.

Alice 在玩魔兽争霸时, 他的建筑被多个敌人攻击, 他需要消耗 t_it 
i
​	
  的时间来消灭攻击第 ii 个建筑的敌人, 而敌人摧毁每个建筑的时间为 d_id 
i
​	
  (如果 t_i \ge d_it 
i
​	
 ≥d 
i
​	
 , 就没必要救了).

Alice 只能一个一个救援, 而敌人同时攻击 Alice 的建筑. 请你帮 Alice 计算他最多可以营救下多少价值的建筑.


Input
输入的第一行为一个正整数 n \in [1,100]n∈[1,100], 表示 Alice 拥有的建筑数量,

后面 nn 行, 每行包含三个正整数 t_i \in [1,20], d_i \in [1,2000], v_i \in [1,20]t 
i
​	
 ∈[1,20],d 
i
​	
 ∈[1,2000],v 
i
​	
 ∈[1,20], 分别表示 Alice 消灭攻击建筑 ii 的敌人的时间, 敌人攻击建筑 ii 的时间以及建筑 ii 的价值.


Output
输出单独的一行, 表示 Alice 可以营救的建筑的最大价值总和.


Sample Input 1 

2
5 6 1
3 3 5
Sample Output 1

1
Sample Input 2 

2
20 40 20
20 41 20
Sample Output 2

40
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int dp[101][101*21];
struct node
{
    int t,d,p,id;
    bool operator<(const node &x)
    {
        return d<x.d;
    }
} a[101];

int solve()
{
    int res = 0;
    for(int i=a[0].t; i<min(2000,a[0].d); i++){
        dp[0][i] = a[0].p;
        res = a[0].p;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=2000; j++)
        {
            if(j<a[i].t||j>=a[i].d)
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = dp[i-1][j];
                if(dp[i-1][j-a[i].t]+a[i].p>dp[i][j])
                {
                    dp[i][j] = dp[i-1][j-a[i].t]+a[i].p;
                }
            }
            if(dp[i][j]>=res)
            {
                res = dp[i][j];
            }
        }
    }
    return res;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i].t>>a[i].d>>a[i].p,a[i].id = i+1;
    sort(a,a+n);
    cout<<solve();
    return 0;
}