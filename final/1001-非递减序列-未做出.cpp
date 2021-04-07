/*
非递减序列
Description

给定一个正整数 mm 以及一个由 nn 个非负整数 x_1,\cdots, x_nx 
1
​	
 ,⋯,x 
n
​	
  构成的序列, 每一轮可以从序列中选取若干个元素并执行如下运算: x_i = (x_i + 1) \bmod mx 
i
​	
 =(x 
i
​	
 +1)modm.

请给出一种方案, 用最少的轮数把给定序列变成一个非递减序列, 输出需要经过的最少的轮数.


Input
输入包含两行,

第一行为两个正整数 n, m \in [1,300000]n,m∈[1,300000], 分别表示序列中元素个数以及模运算中 mm 的值.

第二行为 nn 个整数 x_1, \cdots, x_n \in [0, m-1]x 
1
​	
 ,⋯,x 
n
​	
 ∈[0,m−1], 表示序列中每个元素的值.


Output
输出最少的轮数.


Sample Input 1 

5 7
0 6 1 3 2
Sample Output 1

1
Sample Input 2 

4 6
1 2 3 4
Sample Output 2

0
*/
#include<bits/stdc++.h>
using namespace std;
int ss[300010];
int n, m;
bool check(int x) {
    int pre;
    if (ss[1] + x >= m)pre = 0;
    else pre = ss[1];
    for (int i = 2; i <= n; i++) {
        int tmp = -1;
        if ((ss[i] + x) >= m && (ss[i] + x) % m >= pre)tmp = pre;
        else if (ss[i] <= pre&&ss[i] + x >= pre)tmp = pre;
        else if (ss[i]>pre)tmp = ss[i];
        if (tmp == -1)return false;
        pre = tmp;
    }
    return true;
}
int main() {
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>ss[i]; 
    }
    int ans = 0;
    int l = 0, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) { 
            ans = mid; 
            r = mid - 1; 
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}