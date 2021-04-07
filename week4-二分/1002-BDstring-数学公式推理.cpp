/*
BD String
Description

众所周知，度度熊喜欢的字符只有两个：BB 和 DD。

今天，它发明了一种用 BB 和 DD 组成字符串的规则：

S(1)=BS(1)=B
S(2)=BBDS(2)=BBD
S(3)=BBDBBDDS(3)=BBDBBDD
\cdots⋯
S(n)=S(n−1)+B+reverse(flip(S(n−1))S(n)=S(n−1)+B+reverse(flip(S(n−1))
其中，reverse(s)reverse(s)指将字符串翻转，比如 reverse(BBD)=DBBreverse(BBD)=DBB，flip(s)flip(s)指将字符串中的B替换为 DD，DD替换为 BB，比如 flip(BBD)=DDBflip(BBD)=DDB。

虽然度度熊平常只用它的电脑玩连连看，这丝毫不妨碍这台机器无与伦比的运算速度，目前它已经算出了 S(2^{1000})S(2 
1000
 )的内容，但度度熊毕竟只是只熊，一次读不完这么长的字符串。它现在想知道，这个字符串的第 LL位（从 11 开始）到第RR位，含有的 BB的个数是多少？


Input
第一行一个整数 TT，表示 T(1\leq T\leq 1000)T(1≤T≤1000)组数据。

每组数据包含两个数 LL和 R(1\leq L\leq R \leq 10^{18})R(1≤L≤R≤10 
18
 )。


Output
对于每组数据，输出 S(2^{1000})S(2 
1000
 )表示的字符串的第 LL位到第 RR位中 BB的个数。


Sample Input 1 

3
1 3
1 7
4 8
Sample Output 1

2
4
3
Source

2016"百度之星" - 初赛（Astar Round2A）
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;
ll l, r;
 

ll dfs(ll x){
    if (x == 0) return 0;
    ll m = 0, ans = 0, rest = 0;
    while (m * 2 + 1 < x) m = m * 2 + 1;
    ans = (m + 1) / 2;
    rest = x - m - 1;
    //printf("m = %lld\n", m);
    return ans + rest - (ans - dfs(m - rest)) + 1;
}

int main(){
  int t; scanf("%d", &t);
  while (t--){
    cin >> l >> r;
    printf("%lld\n", dfs(r) - dfs(l - 1));
  }
  return 0;
}