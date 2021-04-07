/*
最大数
Description

给定一个十进制的整数, 以及一个映射 ff, ff 可以把 11 到 99 的数字映射成 11 到 99 的新的值.

你可以执行如下操作至多11 次:

选择一个非空连续子段, 用 f(x)f(x) 替换其中的每一位
求经过上述操作可能得到的最大的数.


Input
输入包含三行,

第一行为一个正整数 n\in [1,2\cdot 10^5]n∈[1,2⋅10 
5
 ] 表示给定的整数长度,

第二行为给定的整数,

第三行为表示映射 ff 的99 个整数, 分别为 f(1), f(2), \cdots, f(9)f(1),f(2),⋯,f(9).


Output
输出经过题目中要求的操作可能得到的最大的数.


Sample Input 1 

4
1234
1 1 4 5 1 1 1 1 1
Sample Output 1

1245
Sample Input 2 

6
912349
1 1 4 5 1 1 1 1 1
Sample Output 2

912459
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string m;
    int f[10];
    scanf("%d",&n);
    cin >> m;

    for(int i=1;i<10;i++)
        scanf("%d",&f[i]);
    
    int flag = 1;
    int i = 0;
    while(flag && i<n){
        int num = m[i] - '0';
        //cout << num <<' '<<f[num]<<endl;
        if(flag == 2 && f[num] < num)
            break;
        if(f[num] > num){
            flag = 2;
            m[i] = f[num] + '0';
        }
        i ++;
    }
    cout << m;
    return 0;
}