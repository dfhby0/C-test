#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double c[32];
double k[3];
double q;
int n,m;
char a,b;
double price;
int dp[3100000];
int main()
{

    scanf("%lf%d",&q,&n);
    int count=0;
    for(int i=1;i<=n;i++)
    {   
        k[0]=k[1]=k[2]=0;
        cin>>m;
        double sum=0;
        bool flag=1;
        for(int j=1;j<=m;j++)
        {
            cin>>a>>b>>price;
            sum+=price;//累加这张发票的价值 
            if(a!='A'&&a!='B'&&a!='C')//只能报销A,B,C三种商品 
            {
                flag=0;
                continue;
            }
            k[a-'A']+=price;//累加单样物品的价值 
            if(sum>1000||k[a-'A']>600)//单张发票总价值不能超过1000且单样物品价值不能超过600 
                flag=0;
        }
        if(flag)//该发票可以报销 
            c[count++]=sum;
    }
    memset(dp,0,sizeof(dp));//初始化
    //因为精度为小数点后两位所以将所有价值都乘以100便于下面的01背包 
    int maxn=(int)(q+0.01*100);
    for(int i=0;i<count;i++)//01背包 
        for(int j=maxn;j>=(int)(c[i]*100);j--)
            if(dp[j]<dp[j-(int)(c[i]*100)]+(int)(c[i]*100))
                dp[j]=dp[j-(int)(c[i]*100)]+(int)(c[i]*100);
    printf("%.2lf\n",double(dp[maxn]/100.0));//注意结果还要除以100 

    return 0;
}