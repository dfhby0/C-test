/*
小朋友才做选择
Description

Alice 小朋友参加商场的促销游戏, 现有 nn 个糖果堆, Alice 要完成一个游戏, 每次从这 nn 个糖果堆中选择其中的一个, 直到拿完所有的糖果堆.

假设选择的这一个有 xx 个糖果, 则需要从剩下的所有糖果堆中移除糖果数量为 x-1x−1 以及 x+1x+1 的糖果堆.

问 Alice 小朋友最多能拿到多少数量的糖果.


Input
输入的第一行为一个正整数 n\in [1,100000]n∈[1,100000], 表示糖果堆的个数.

第二行为 nn 个正整数, 每一个正整数 x_i \in [1,100000]x 
i
​	
 ∈[1,100000] 表示当前糖果堆中糖果的数量.


Output
输出单独一行, 表示 Alice 最多能获得的糖果数量.


Sample Input 1 

10
1 1 1 1 1 1 2 3 4 4
Sample Output 1

14
Sample Input 2 

5
5 3 5 3 4
Sample Output 2

16
Hint

如第二组样例，先拿 3，去掉 2, 4(序列中没有 2), 还剩下 5 5 3，再拿 5，去掉 4, 6(剩下序列中都没有), 还剩下 5 3, 一次类推, 最大值为 3 + 5 + 5 + 3 = 16

*/

#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int q[N],p[N];
int s[N];
int n;

int main(){
    scanf("%d",&n);
    memset(s,sizeof(s),0);
    int maxn=0;
    for(int i = 0; i < n; i ++){
        scanf("%d",&q[i]);
        s[q[i]]++;
        if(q[i]>maxn)
            maxn = q[i];
    }
    p[1] = s[1] * 1;
    p[2] = max(s[2] * 2,p[1]);
    p[3] = max(s[3] * 3 + p[1], p[2]);
    for(int i = 4; i < maxn + 1; i ++){
        p[i] = max(p[i-2] + s[i] * i,max(p[i-3] + s[i-1]*(i-1),p[i-1]));
    }

    printf("%d",p[maxn]);

    return 0;
}

