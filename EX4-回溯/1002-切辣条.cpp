/*
切辣条
Description

Alice 有若干根等长的辣条, 现在她把这些辣条切成了 nn 份, 现在 Alice 想把这些辣条拼回去, 但是 Alice 忘记了原来辣条的数量和长度,

请你帮她计算原有辣条的最小可能长度.


Input
输入包含两行,

第一行为一个正整数 n \in [2, 64]n∈[2,64], 表示切完的辣条的数量.

第二行为 nn 个正整数 a_1, \cdots, a_n \in [1,50]a 
1
​	
 ,⋯,a 
n
​	
 ∈[1,50], 表示现在每一段辣条的长度.


Output
输出一个正整数, 表示原有辣条可能的最小长度.


Sample Input 1 

7
9 3 1 4 1 9 9
Sample Output 1

9
*/

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