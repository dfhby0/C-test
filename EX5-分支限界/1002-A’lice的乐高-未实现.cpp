/*
Alice 的乐高
Description

Alice 小朋友最近迷上了乐高玩具,玩具分为 A, B, C 三个种类, 现在 Alice 想让妈妈帮他买一些玩具.

为了促销, 商场以大礼包的形式进行玩具销售(不单卖), 妈妈要求 Alice 选择的每个大礼包的总价不能超过 10001000 元, 而且同一种类玩具的价格不能超过 600600 元, 但是可以买多个大礼包.

请你帮 Alice 找出他可以买的玩具的总价值最大值.


Input
输入的第一行包含两个数 m, nm,n, mm 为妈妈给 Alice 买玩具的总预算(浮点数), n\in [1,30]n∈[1,30] 表示大礼包的数量.

后续 nn 行, 每行的格式为: 't A:a1 B:b1 C:c1 ...', 其中 t \in [1,10]t∈[1,10] 表示大礼包中玩具的数量, A,B,CA,B,C 均表示玩具种类, a1,b1,c1a1,b1,c1 分别表示每种玩具的价格(浮点数),每个大礼包中相同种类的玩具可能会重复出现.


Output
输出单独一行, 表示 Alice 能买到的玩具的的总价值最大值, 输出结果保留两位小数.


Sample Input 1 

1200.00 2
2 B:600.00 A:400.00
1 C:200.50
Sample Output 1

1000.00
Sample Input 2 

1200.50 3
2 B:600.00 A:400.00
1 C:200.50
1 A:100.00
Sample Output 2

1200.50
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,i;
double m;
int L[32];

int main(){
    cin>>m>>n;
 for(int i=0;i<n;i++){
  int t;
  scanf("%d",&t);
  //cout<<"t:"<<t<<endl;
  double sum=0;
  double sumA=0;
  double sumB=0;
  double sumC=0;
  while(t>0){
   double price;
   char c;
   getchar();
   scanf("%c:%lf", &c, &price);
   //cout<<th.substr(4,th.find("\t"))<<endl;
    
     if(c=='A') sumA+=price;
    else if(c=='B') sumB+=price;
    else if(c=='C') sumC+=price; 
     sum+=price;
    t--;
  }
  if(sum>1000||sumA>600||sumB>600||sumC>600) {
   L[i]=0;
  }else{
  // cout<<"sum:"<<sum<<endl;
  // cout<<"sumA:"<<sumA<<endl;
  // cout<<"sumB:"<<sumB<<endl;
  // cout<<"sumC:"<<sumC<<endl;
   L[i]=(int)(sum*100);
  }
  
 }

        int u = (int) (m * 100);
        int *dp = new int[u + 1];
        for(i = 0; i < u+1; i++){
            dp[i] = 0;
        }
        for (i = 0; i <n ; i++) {
            int l = L[i];
            for (int j = u; j >= l; j--) {
                dp[j] = max(dp[j], dp[j - l] + l);
            }
        }
        double res = (double)(dp[u]/100.00);
        printf("%.2lf\n",res);
    
    return 0;
}