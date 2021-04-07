/*
字符串排序
Description

给定一组字符串, 现在希望把这一组字符串调整为按字典序排列的情形.

要求: 不能变换字符串的相对位置, 只能对某些字符串进行反转操作.

反转一个字符串有一定的消耗(设为 c_ic 
i
​	
 ), 求一个方案使得最终总的消耗最小, 输出最小的消耗.


Input
输入的第一行为一个正整数 n \in [2,100000]n∈[2,100000] 表示改组字符串的个数.

第二行为 nn 个整数 c_i \in [0,10^9]c 
i
​	
 ∈[0,10 
9
 ], 表示反转第 ii 个字符串的开销.

接下来 nn 行, 每一行为一个字符串, 字符串长度不超过 100000100000.


Output
输出最小的总开销, 如果不存在可行的方案使得这组字符串按字典序排列, 则输出 "-1−1".


Sample Input 1 

2
1 2
ba
ac
Sample Output 1

1
Sample Input 2 

2
5 5
bbb
aaa
Sample Output 2

-1
Sample Input 3 

4
0 0 8 6
bi
qp
bt
ya
Sample Output 3

8
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const unsigned long long INF = 100000000000000000;
int n;
unsigned long long S[N][2],spend[N];
string s[N][2];

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        cin >> spend[i];
        S[i][0] = INF;
        S[i][1] = INF;
    }

    for(int i = 0; i < n; i ++){ 
        string temp_s;
        cin >> temp_s;
        s[i][0] = temp_s;
        reverse(temp_s.begin(),temp_s.end());
        s[i][1] = temp_s;
    }
    S[0][0] = 0;
    S[0][1] = spend[0];
    for(int i = 1; i < n; i ++){
        unsigned long long a=INF,b=INF,c=INF,d=INF;
        if(s[i][0] >= s[i-1][0] && S[i-1][0]!=INF){
            a = S[i-1][0];
            //cout<<'a'<<' '<<a<<endl;
        }
        if(s[i][0] >= s[i-1][1] &&  S[i-1][1]!=INF){
            b = S[i-1][1];
            //cout<<'b'<<' '<<b<<endl;
        }
        S[i][0] = min(a,b);
        if(s[i][1] >= s[i-1][0] && S[i-1][0]!=INF){
            c = S[i-1][0] + spend[i];
            //cout<<'c'<<' '<<c<<endl;
        }
        if(s[i][1] >= s[i-1][1] &&  S[i-1][1]!=INF){
            d = S[i-1][1] + spend[i];
            //cout<<'d'<<' '<<d<<endl;
        }
        S[i][1] = min(c,d);
        //cout << S[i][0] << ' ' << S[i][1] << endl;
    }
    int sss = -1;
    if((S[n-1][0]==INF && S[n-1][1]==INF))
        printf("%d",sss);
    else
        cout << min(S[n-1][0],S[n-1][1]) <<endl;
    
    //int ssss;
    //cin>>ssss;

    return 0;
}
