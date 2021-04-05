
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
    while((high-low)> eqs )
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
