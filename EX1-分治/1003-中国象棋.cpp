/*
中国象棋
Description

在中国象棋中, "車" 只能水平或垂直前进.

现在有一个不规则的棋盘, 棋盘有若干列, 每一列高度不同(底部互相持平).

你有一个棋子"車", 现在要走遍棋盘的每一个格子, 每次可以在一个水平或垂直方向选择任意的起点和终点(不能跨过棋盘边界). 求最少需要走的次数.


Input
第一行为一个正整数 n \in [1,5000]n∈[1,5000].

后续 nn 行, 每一行为一个正整数 a_i \in [1,10^9]a 
i
​	
 ∈[1,10 
9
 ].


Output
单独一行, 输出最少要走的次数.


Sample Input 1 

7
4
5
2
2
2
1
5
Sample Output 1

5
Hint
*/

#include<bits/stdc++.h>
using namespace std;
int q[5010];
int find_line(int left, int right, int cut){
    if(left == right){
        if(q[left] - cut==0)return 0;
        return 1;
    }
    if(left > right)
        return 0;

    int flag1 = 0;
    for(int i = left; i <= right; i ++){
        if(q[i] - cut !=0){
            flag1 = 1;
            break;
        }
    }
    if(!flag1)return 0;

    int flag = 0;
    int minn = 1000000000;
    for(int i = left; i <= right; i ++){
        if(q[i] - cut < minn ){
            flag = i;
            minn = q[i] - cut;
        }
    }
    
    int a = find_line(left, flag - 1, cut + minn) + find_line(flag + 1, right , cut + minn) + minn;
    int d = find_line(left, flag - 1, cut) + find_line(flag + 1, right , cut) + 1;
    //cout << left <<' '<<flag<<' '<<right << ' ' << a <<' '<< d << ' ' << minn << ' ' << cut << endl;
    //cout << a <<' '<<b<<' '<<c << ' '<< d<< endl;
    return min(a,d);
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
        scanf("%d",&q[i]);
    //sort(q,q+n);
    printf("%d",find_line(0,n-1,0));
}