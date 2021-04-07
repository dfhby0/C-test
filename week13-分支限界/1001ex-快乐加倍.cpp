/*
快乐加倍
Description

班上有 nn 个同学, 为了让大家圣诞节快乐加倍, 老师准备把 kk 升饮料分给同学们(每个人得到的饮料体积可能为小数),

如果两个同学是好朋友, 那么他们得到的快乐总和为两个人分得的饮料体积的乘积.

求一种分发的方案, 使得所有人快乐的总和最大, 输出最大的快乐值.

(没有好朋友的不发饮料）


Input
输入的第一行为两个正整数 n \in [1,40], k\in [1,1000]n∈[1,40],k∈[1,1000],

后续 nn 行, 第 ii 行包含 nn 个整数 a_{i,1}, a_{i,2}, \cdots, a_{i,n} \in \{0,1\}a 
i,1
​	
 ,a 
i,2
​	
 ,⋯,a 
i,n
​	
 ∈{0,1}, 如果 a_{i,j}=1a 
i,j
​	
 =1, 则表示 ii 和 jj 是好朋友, 如果 a_{i,j}=0a 
i,j
​	
 =0, 则表示  ii 和 jj 不是好朋友.


Output
输出最大的快乐值, 保留 6 位小数.


Sample Input 1 

3 1
0 1 0
1 0 0
0 0 0
Sample Output 1

0.250000
Sample Input 2 

4 4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
Sample Output 2

4.000000
*/

#include<bits/stdc++.h>
using namespace std;

int n;
double k;
int maxn = 0;
int friends[50][50];
int flag[50] = {0};
void max_friend(int thisk,int count){
    for(int i = thisk+1; i < n; i++){
        if(count + 1 + (n - 1) - i < maxn)return;
        bool sign = true;
        for(int j = 0;j < count;j++){
            if(friends[flag[j]][i]==0){
                sign = false;
                break;
            }
        }
        if(sign){
            flag[count] = i;
            max_friend(i,count+1);
        }
    }
    if(maxn < count){
        maxn = count;
    }
}

int main(){
    
    cin >> n >> k;
    for(int i = 0; i < n ; i ++)
        for(int j = 0 ; j < n ;j ++)
            cin >> friends[i][j];
    for(int i = 0;i < n; i++){
        if(n - i < maxn)break;
        flag[0] = i;
        max_friend(i,1);
    }

    printf("%.6f",(k/maxn * k/maxn) * (maxn * (maxn-1))/2);

    return 0;

}