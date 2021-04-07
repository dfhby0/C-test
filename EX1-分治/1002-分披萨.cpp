/*
分披萨
Description

现在要把 nn 个披萨分给 m+1m+1 个人, 要求每个人得到的面积相同(不能拼凑, 每个人得到的披萨需要是完整的, 可以不规则), 为了减少浪费, 希望每个人得到的面积最大.

求满足要求的分完每个人的最大面积.


Input
第一行输入两个正整数 n, m \in [1,10000]n,m∈[1,10000].

接下来 nn 行,每行包含一个正整数, 表示每个披萨的半径.


Output
单独一行, 输出每个人得到的最大披萨面积, 结果保留 4 位小数.


Sample Input 1 

7 9
25
13
14
13
3
27
9
Sample Output 1

530.9292
Sample Input 2 

5 2
15
25
8
24
15
Sample Output 2

981.7477
Hint

pi = acos(-1.0);
*/


#include <bits/stdc++.h>

using namespace std ;
#define PI acos(-1.0)
#define eqs 1e-6
double s[11000] ;
int n , m ;
double f(double x)
{
    int k = (x+eqs) * 10000 ;
    x = k * 1.0 / 10000 ;
    return x ;
}
int solve(double x)
{
    int i , j , num = 0 ;
    for(i = n-1 ; i >= 0 && (s[i]-x) > eqs ; i--)
    {
        j = s[i] / x ;
        num += j ;
        if( num >= m + 1)return 1 ;
    }
    if( num >= m + 1 ) return 1 ;
    return 0 ;
}
int main()
{
    int i , k ;
    double low , mid , high , last ;

    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++)
        scanf("%lf", &s[i]) ;
  	for(i = 0 ; i < n ; i++)
      s[i] = s[i]*s[i]*PI;
    sort(s,s+n) ;
    low = 0 ;
    high = s[n-1] ;
    while( (high-low) > eqs )
    {
        mid = (low+high)/2.0 ;
        if( solve(mid) )
        {
            low = mid  ;
            last = mid ;
        }
        else
            high = mid ;
    }
    double sss = 0.0000;
    if(last < 0.0100){
        printf("%.2lf\n", sss) ;
    }
    else{
        printf("%.4lf\n", last) ;
    }

    return 0;
}
