/*
Alice 的烦恼
Description

Alice 是某大厂的程序员, 由于年龄到了35岁面临被裁员, 他准备去广场摆摊卖烤冷面. 为了控制成本, Alice 买了 nn 根散装火腿肠作为重要原料. 这就带来了一个问题, 由于生产流程不够标准化, 火腿肠的长度各不相同.

为了保证买卖公平, 明码标价, 现在 Alice 准备把这些火腿肠切成等长的 mm 份, 为了保证口感, 他还同时希望每一份的长度越长越好, 你能写出一个算法帮他算出每一份的最大长度吗?


Input
输入的第一行为两个正整数 n, m \in [1,10000]n,m∈[1,10000], 分别代表火腿肠的总数以及 Alice 要切的份数.

后面 nn 行, 每一行为一个浮点数, 表示火腿肠的长度.


Output
输出切分后的火腿肠的最大长度, 结果保留两位小数(如果最终切分的结果小于 0.010.01, 输出 0.000.00 表示创业失败).


Sample Input 1 

5 10
11.16
76.45
98.51
5.79
60.96
Sample Output 1

20.32
Hint

注意精度!!!

注意精度!!!

注意精度!!!
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
#define PI 1
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
        if( num >= m )return 1 ;
    }
    if( num >= m ) return 1 ;
    return 0 ;
}
int main()
{
    int i , k ;
    double low , mid , high , last ;

    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++)
        scanf("%lf", &s[i]) ;
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
        printf("%.2lf\n", floor((last+0.0001)*100)/100) ;
    }

    return 0;
}
