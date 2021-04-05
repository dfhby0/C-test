#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[10][10];
int nsum = 0;

void backtrack(int num,int total){
    if(total == m){
        nsum++;
        return;
    }
    if(num==n){
        return;
    }
    for(int i = 0;i < n;i++){
        if(board[num][i]==1){
            int temp[10];
            for(int j = 0;j<n;j++){
                temp[j] = board[j][i];
                board[j][i] = 0;
            }
            backtrack(num+1,total+1);
            for(int j = 0;j<n;j++)board[j][i] = temp[j];
        }
    }
    backtrack(num+1,total);
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < n;j++){
            if(s[j]=='.')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
    backtrack(0,0);
    cout << nsum;
    return 0;
}