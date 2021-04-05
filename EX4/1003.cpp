#include<bits/stdc++.h>
using namespace std;
int flag[1000000] = {0};
int b[10][10];

void backtrack(int i,int j,int num,int total,int m){
    if(b[i][j]==10)return;
    if(num==total){
        flag[m] = 1;
        return;
    }
    backtrack(i+1,j,num+1,total,m+b[i][j]*(pow(10,(5-num))));
    backtrack(i-1,j,num+1,total,m+b[i][j]*(pow(10,(5-num))));
    backtrack(i,j+1,num+1,total,m+b[i][j]*(pow(10,(5-num))));
    backtrack(i,j-1,num+1,total,m+b[i][j]*(pow(10,(5-num))));
}

int main(){
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0;i <=6 ;i++){
        b[0][i] = 10;
        b[6][i] = 10;
        b[i][0] = 10;
        b[i][6] = 10;
    }

    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j++){
            backtrack(i,j,0,6,0);
        }
    }

    int count = 0;
    for(int i = 0; i < 1000000;i++){
        count  = count + flag[i];
    }

    cout << count;
    return 0;
}
