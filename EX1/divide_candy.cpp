#include<bits/stdc++.h>
using namespace std;
int n,m;
int *room;
int LL=0;
void fenzhi2(int be,int en){
	if(abs(be-en)<=1) {
		int sum=0;
		for(int i=1;i<=n;i++){
			if(room[i]<=be) sum++;
			else{
				if(room[i]%be>0) sum=sum+room[i]/be+1;
				else sum+=room[i]/be;
			}
		}
		if(sum==m) LL=be;
		else LL=en;
		return;
	}else{
		int midnum=(be+en)/2;
		//cout<<"midnum:"<<midnum<<endl;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(room[i]<=midnum) sum++;
			else{
				if(room[i]%midnum>0) sum=sum+room[i]/midnum+1;
				else sum+=room[i]/midnum;
			}
		}
		//cout<<"sum:"<<sum<<endl;
		if(sum>m) fenzhi2(midnum,en);
		else fenzhi2(be,midnum);
	}
}
int main(){
	cin>>n>>m;
	room=new int[n+1];
	for(int i=0;i<n;i++){
		cin>>room[i+1];
	}
 
	room[0]=0;
	sort(room,room+n+1);
	//for(int i=0;i<n+1;i++) cout<<room[i]<<endl;
	if(m==n){
		cout<<room[n]<<endl;
	}else{
	fenzhi2(0,room[n]);
	cout<<LL<<endl;
	}
	
	
}
