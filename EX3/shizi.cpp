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
