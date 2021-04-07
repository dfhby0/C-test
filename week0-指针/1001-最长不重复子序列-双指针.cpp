/*
最长不重复子序列
Description
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

Input
输入包含两行，第一行为一个正整数 n(n\in (0,10000000])n(n∈(0,10000000])，第二行为一个长度为 nn 的字符串。

Output
输出单独的一行，即给定的最长不重复子串的长度。

Sample Input 1 
8
abcabcbb
Sample Output 1
3

Sample Input 2 
5
bbbbb
Sample Output 2
1

Sample Input 3 
6
pwwkew
Sample Output 3
3
*/

/*
使用一个数组来储存某字符已有的个数，
利用双指针的方式取出不含重复字符的区间，从而在每次指针移动时可以找到当前最长的不重复字符串长度，由于最长字符串的下端永远小于等于上端，从而最慢为O(2n)
*/

#include<iostream>

using namespace std;

const int N  = 10000010;

int n;
char a[N];
int s[N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i ++) cin >> a[i];
  
  int res = 0;
  for (int i = 0,j = 0; i < n; i ++)
  {
    s[a[i]] ++;
    while(s[a[i]] > 1)
    {
      s[a[j]] --;
      j ++;
    }
    res = max(res, i - j + 1);
  }
  
  cout << res << endl;
  
  return 0;
}
  