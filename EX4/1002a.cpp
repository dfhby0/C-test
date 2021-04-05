#include <bits/stdc++.h>
using namespace std;
const int maxn = 65;
bool visited[maxn];
int values[maxn];
bool flag;
int parts;
int len;
int n;
 
void backtrack(int pos,int cur,int cnt){
	if(cur == len){
		cnt++;
		if(cnt == parts){
			flag = true;
			return ;
		}
		backtrack(0,0,cnt);
	}
	if(pos >= n){
		return ;
	}
	int i;
	for(i = pos ; i < n ; ++i){
		if(visited[i] == false  && values[i] + cur <= len){
			visited[i] = true;
			backtrack(i+1,values[i]+cur,cnt);
			visited[i] = false;
			if(flag == true|| pos == 0){
				return ;
			}
		}
	}
}
 
int main(){
    int maxLen = -1;
    int sum = 0;
    int i;
    cin >> n;
    for(i = 0 ; i < n ; ++i){
        cin >> values[i];
        if(values[i] > maxLen){
            maxLen = values[i];
        }
        sum += values[i];
    }
    for(len = maxLen ; len < sum ; ++len){
        if(sum%len == 0){
            memset(visited,false,sizeof(visited));
            parts = sum/len;
            flag = false;
            backtrack(0,0,0);
            if(flag == true){
                break;
            }
        }
    }
	cout << len;
	return 0;
}
