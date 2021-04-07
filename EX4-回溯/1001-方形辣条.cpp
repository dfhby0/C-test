/*
方形辣条
Description

Alice 买了很多根辣条, 这些辣条的长短不尽相同, 现在她想把这些辣条拼在一起变成一个方形辣条(边长都相等), 请问有没有可行的方案.

(所有辣条都要用上)


Input
输入包含两行, 第一行为一个正整数 n \in [4,20]n∈[4,20], 表示辣条的数量,

第二行为 nn 个正整数 a_1, \cdots, a_n \in [1,10000]a 
1
​	
 ,⋯,a 
n
​	
 ∈[1,10000], 表示每根辣条的长度.


Output
如果存在可行的方案, 输出 'yes', 否则输出 'no'.


Sample Input 1 

8
6 11 8 1 7 7 20 20
Sample Output 1

yes
*/

#include<bits/stdc++.h>
using namespace std; 
int nums[21];
int n;

bool backtrack(int num, int total, int side[]) {
        if (num == n) {
            return (side[0] == side[1] && side[1] == side[2] && side[2] == side[3]);
        }
        for (int i = 0; i < 4; i++) {
            if (side[i] + nums[num] > total) {
                continue;
            }
            side[i] += nums[num];
            if (backtrack(num + 1, total, side)) {
                return true;
            }
            side[i] -= nums[num];
        }

        return false;
    }

bool cmp(int a,int b){
    return a>b;
}

bool issquare(){
    int sum = 0;
    for(int i = 0;i<n;i++)sum=sum+nums[i];
    if (sum % 4 != 0) {
        return false;
    }
    int side_long = sum / 4;
    int side[4] = {0};
    return backtrack(0, side_long, side);
}
 
int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i ++)cin>>nums[i];
    sort(nums,nums+n,cmp);
    if (issquare() == true)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}