/*
棋盘游戏
Description

一个棋子以任意格子为起点,在一个 5\times 55×5 的棋盘上移动, 每次只能向上、下、左、右任意一个方向移动一格(不能超过棋盘边界).

每一轮该棋子恰好移动 55 次, 棋盘的每个格子都有一个数字, 棋子经过的这些数字可以组成一个新的数(66位),

请问通过上述移动规则最多可以组成多少个不同的数（可能存在前导0，如 000111）.


Input
输入包含 55 行, 每行 55 个整数 a_1, \cdots, a_5 \in [0,9]a 
1
​	
 ,⋯,a 
5
​	
 ∈[0,9]

Output
输出单独一行, 表示所有可能组成的数的个数.


Sample Input 1 

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
Sample Output 1

15
*/

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
