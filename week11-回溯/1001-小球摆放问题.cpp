/*
小球摆放问题
Description

n \times nn×n 的棋盘上有若干个盒子(棋盘的每个格子最多放一个盒子),

现有若干个同样的小球要放入盒子中, 每个盒子中最多放一个小球, 且任意两个有小球的盒子不能在棋盘上共线(行或列均不能相同).

请问共有多少种可行的方案.


Input
输入的第一行为两个正整数 n,m(m\leq n \leq 8)n,m(m≤n≤8), 分别表示棋盘的大小和小球的数量.

随后 nn 行, 每行 nn 个字符, '#' 表示棋盘的当前格子中有盒子, '.' 表示当前格子中无盒子.


Output
输出可能的方案总数.


Sample Input 1 

3 1
...
###
...
Sample Output 1

3
Sample Input 2 

4 4
..#.
.#.#
.#..
##.#
Sample Output 2

1
*/

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