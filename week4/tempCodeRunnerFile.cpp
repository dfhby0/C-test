#include<bits/stdc++.h>

using namespace std;
const double INF = 1e20;
const int N = 100010;

struct P
{
    double x;
    double y;
}p[N];
int n;
int temp[N];

bool com1(const P& a,const P& b)
{
    if(a.x != b.x)return a.x < b.x;
    return a.y < b.y;
}

bool com2(const int& a,const int& b)
{
    return p[a].y < p[b].y;
}

double dis(int i, int j)
{
    return sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x)
                + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}

double min(double a,double b)
{
    return a < b ? a : b;
}

double min_distance(int left, int right)
{
    double d = INF;
    if (left==right)return d;
    if (left + 1 == right)return dis(left, right);
    int mid = (left + right) >> 1;
    double d1 = min_distance(left,mid);
    double d2 = min_distance(mid + 1,right);
    d = min(d1,d2);

    int i,j,k=0;
    for(i = left; i <= right; i++)
    {
        if(fabs(p[mid].x - p[i].x) <= d)
            temp[k++] = i;
    }

    sort(temp,temp+k,com2);

    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && p[temp[j]].y - p[temp[i]].y < d; j++)
        {
            double d3 = dis(temp[i],temp[j]);
            if (d > d3)
                d = d3;
        }
    }

    return d;
}


int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%lf %lf",&p[i].x,&p[i].y);
    sort(p,p+n,com1);

    double ans = min_distance(0,n-1);
    if(ans != INF && ans < 10000)printf("%.4lf",ans);
    else puts("INFINITY");

}