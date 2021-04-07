/*
最长对称子串
Description
输入一个字符串，输出该字符串中对称的子字符串的最大长度（如 `aba`, `abba` 均为对称字符串）

Input
输入包含两行, 第一行为一个正整数 n(n\in (0,100000])n(n∈(0,100000]), 表示字符串的长度，第二行为一个长度为 nn 的字符串.

Output
输出为单独一行, 即给定字符串的对称子串的最大长度.
Sample Input 1 
5
aaaaa
Sample Output 1
5
Sample Input 2 
5
aabac
Sample Output 2
3
*/

 /*
马拉车算法！
首先通过预处理，在各个字符之间加上#，从而使原来不同奇偶个数的字符都变成奇数
定义p[i]为以第i个字符为中心的最长回文半径，从而原来字符串在当前位置的最长回文长度为p[i]-1
确定了回文长度，我们可以通过（i-p[i]）/2得到回文序列的起始索引
为保证奇回文在这一计算中不会变为-1，在开头增加一个@字符
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;

    cin>>n;
    cin>>s;

    if(s.size() < 1) return 0;
    if(s.size() == 1) return 1;

    string str = "@#";
    for(int i = 0;i < s.size();i++) {
        str += s[i];
        str += '#';
    }

    std::vector<int> p(str.size(),0);
    
    int mx = 0, id = 0,start = 0,maxlen = 0;
    for (int i = 1; str[i] != '\0'; i++)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (str[i + p[i]] == str[i - p[i]]) p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    if(p[i]-1 > maxlen)
    {
        start = (i-p[i])/2;
        maxlen = p[i]-1;
    }
    }
    cout<<s.substr(start,maxlen).size();
}