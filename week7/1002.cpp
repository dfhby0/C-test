#include<bits/stdc++.h>
using namespace std;
int n;
'''
    主要思路是找到相关联的项，这里只有前一项的顺序会影响后面
    之后确定每一步的状态数：共4种：对于每个字符串，有两个状态，因此相邻两项进行四个判断
    并在每一状态满足条件时记录下值 
    状态一:后一项不反转min(S[i-1][0],S[i-1][1]) 
    状态二:后一项反转min(S[i-1][0] + spend[i],S[i-1][1] + spend[i])
    数据过长，使用unsigned long long重新定义
'''
struct B{
    int v;
    int q;
    int r;
    int sign;
}b[110];


bool cmp(const B &x,const B &y)
{
    return x.v < y.v;
}

bool cmp1(const B &x,const B &y)
{
    return x.q < y.q;
}

int main(){
    scanf("%d",&n);
    int maxn = 0;
    for(int i = 0;i < n; i ++){
        cin >> b[i].q;
    }
    for(int i = 0;i < n; i ++){
        cin >> b[i].v;
        b[i].r = b[i].v - b[i].q;
        maxn = maxn + b[i].q;
    }

    sort(b,b+n,cmp);

    int total_v = 0;
    int flag,min_num=0,max_num=0;
    for(int i = n-1; i >= 0;i --){
        total_v = total_v + b[i].v;
        b[i].sign = 1;
        min_num++;
        max_num++;
        if(total_v >= maxn){
            flag = i;
            break;
        }
    }

    int res = 0;

    for(int i = flag - 1; i >= 0; i --){
        total_v = total_v - b[flag].v + b[i].v;
        if(total_v >= maxn){
            flag = i;
            b[i].sign = 1;
            max_num++;
        }
        else{
            res = res + b[i].q;
        }
        cout << maxn <<' '<< total_v<<' '<< res <<' '<<min_num <<' '<<max_num <<endl;
    }

    int num=max_num-min_num;
    int count = 0;
    sort(b,b+n,cmp1);
    for(int i = 0; i < n; i ++){
        cout<<b[i].sign <<' '<<b[i].q <<' '<< b[i].v<<endl;
    }

    for(int i = 0; i < n; i ++){
        
        if(count >= num)break;
        if(b[i].sign == 1){
            count++;
            res = res + b[i].q;
        }
    }

    printf("%d %d",min_num,res);
    
    int sss;
    cin >> sss;

    return 0;

}


