#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	vector<int> a;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
    if(n<2 || k==1){
        cout<< 0;
        return 0;
    }
	sort(a.begin(),a.end());
//	for(int i=0;i<a.size();i++) cout<<a[i]<<endl;
	bool flag=false;
	int lunci=0;
	while(1>0){
		map<int,int> record;
		record.erase(record.begin(),record.end());
		int maxnum=0;
		int maxindex=0;
		for(int i=0;i<a.size();i++){
			if(record.find(a[i])!=record.end()){
				map<int,int>::iterator iter=record.find(a[i]);
				int tmp2=iter->second;
				
				record[a[i]]=tmp2+1;
				if(record[a[i]]>maxnum){
					maxnum=record[a[i]];
					maxindex=a[i];
				}
				if(record[a[i]]==k){
					flag=true;
					break;
				}
			}else{
				record.insert(pair<int,int>(a[i],1));
				if(record[a[i]]==k){
					flag=true;
					break;
				}
			}
		}
		if(flag){
			break;
		}else{
			if(a[a.size()-1]-maxindex<=maxindex-a[0]){
				a[a.size()-1]-=1;
			}else{
				a[0]+=1;
			}
			sort(a.begin(),a.end());
			//for(int i=0;i<a.size();i++) cout<<a[i]<<endl;
			lunci++;
		}
	}
	cout<<lunci<<endl;
}
