/*
取石子小游戏
Description

现有 nn 个盒子, 每个盒子中有一定数量的石子, 每一轮可以选择一个正整数 i(2\cdot i + 1 \leq n)i(2⋅i+1≤n), 同时拿出编号为 i,2\cdot i,2\cdot i + 1i,2⋅i,2⋅i+1 的盒子中的一个石子(如果箱子里面没有石子了则不拿).

请编程计算最少经过多少轮可以使所有盒子都为空.


Input
输入包含两行,

第一行为一个正整数 nn, 表示盒子的数量,

第二行为由空格隔开的 nn 个正整数 a_1,a_2,\cdots a_na 
1
​	
 ,a 
2
​	
 ,⋯a 
n
​	
  表示每个盒子中石子的数量.


Output
输出单独的一行, 表示要使所有盒子均为空至少需要的轮数.

如果无法使盒子均为空, 输出 -1−1.


Sample Input 1 

1
1
Sample Output 1

-1
Sample Input 2 

3
1 2 3
Sample Output 2

3
*/

#include<bits/stdc++.h>
using namespace std;
int n;
int rock[105];
int main(){
	cin>>n;
	int sum=0;
	int res = 0;
	for(int i=0;i<n;i++){
		cin>>rock[i];
		sum+=rock[i];
	}
	if(n<3 || n%2==0){
		cout<<-1<<endl;
	}
	else{
		int mid=(n-1)/2;
		int res=0;
		
		while(sum!=0){
			int maxnum=0;
			for(int i=1;i<=mid;i++){
				if(2*i>mid){
					maxnum=max(rock[2*i-1],rock[2*i]);
					rock[i-1]=max(rock[i-1]-maxnum,0);
					rock[2*i]=0;
					rock[2*i-1]=0;
					res+=maxnum;
				}else{
					if(2*i+1>mid){
						maxnum=rock[2*i];
						rock[i-1]=max(rock[i-1]-maxnum,0);
						rock[2*i-1]=max(rock[2*i-1]-maxnum,0);
						rock[2*i]=0;
						res+=maxnum;
					}
				}
			}
			mid=mid/2;
			sum=0;
			for(int i=1;i<n;i++){
				sum+=rock[i];
			}
			
		}
		if(rock[0]==0){
			cout<<res<<endl;
		}else{
			cout<<res+rock[0]<<endl;
		}
	}
}
