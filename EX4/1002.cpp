#include<bits/stdc++.h>
using namespace std;
int flag[64] = {0};
int l[64];
int n;
int total = 0;
int b = 0;
int sum=0;
int len;
bool cmp(int a,int b){
    return a>b;
}
void backtrack(int num,int cur_long,int cur_count){
    if(cur_long==len){
        cur_count++;
        if(cur_count==total){
            b=1;
            return;
        }
        backtrack(0,0,cur_count)
    }

    if(num==n){
        return;
    }

    for(int i = num+1;i<n;i++){
        if(flag[i]==1&&cur_long + l[i] > len)continue;
        flag[i] = 1;
        backtrack(i+1,cur_long + l[i],cur_count);
        flag[i] = 0;
        if(b == 1|| num == 0){
			return ;
		}
    } 
}

int main(){
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> l[i];
        sum = sum+l[i];
    }

    sort(l,l+n);
    for(int i = l[n];i<=sum;i++){
        if(b==1)break;
        if(sum%i==0){
            memset(flag,sizeof(flag),0);
            total = sum/i;
            len = i;
            backtrack(0,0,i);
        }
    }
    cout << len;
    return 0;
}
