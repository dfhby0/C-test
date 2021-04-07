/*
寻找重复数
Description
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
要求算法复杂度为 O(1) (不包括输入数组).

Input
输入包含两行, 第一行为一个正整数 n, 第二行为 n + 1 个正整数.

Output
输出为单独一行, 即所有给出的数中重复的数.

Sample Input 1 
4
1 3 4 2 2
Sample Output 1
2

Sample Input 2 
4
3 1 3 4 2
Sample Output 2
3

*/

/*
使用一个数组来储存某字符已有的个数，在输入的时候同时将数字出现的个数储存起来，从而当出现重复的时候直接输出
*/

#include<iostream>

using namespace std;

const int N  = 10000010;

int n;
int a;
int s[N];

int main()
{
  scanf("%d",&n);
  for (int i = 0; i < n + 1; i ++)
  {
    scanf("%d",&a);
    s[a]++;
    if(s[a] > 1)
    {
      cout << a << endl;
      break;
    }
  }
  return 0;
}
  