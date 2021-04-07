/*
链表排序
Description

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3

输出: 1->2->3->4

示例 2:

输入: -1->5->3->4->0

输出: -1->0->3->4->5


Input
输入包含两行，第一行为一个整数 nn (1 ≤ n≤ 100000)用空格隔开，第二行为 n 个整数，用空格隔开，表示链表每一个节点的值


Output
输出单独的一行，即链表排序后的结果，用空格隔开


Sample Input 1 

4
4 2 1 3
Sample Output 1

1 2 3 4
Sample Input 2 

5
-1 5 3 4 0
Sample Output 2

-1 0 3 4 5
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
const int maxn = 1e6 + 10;

vector<P>v;
int a[maxn];
int e[maxn],ne[maxn];

int main()
{
    int n,x;
    int idx = 0;
    int head = -1;
    bool flag = false;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d",&x);
        if(i==0)
        {
            idx ++;
            head ++;
            ne[head] = -1;
            e[head] = x;
        }
        else
        {   
            ne[idx-1] = idx;
            ne[idx] = -1;
            e[idx] = x;
            idx ++; 
        }
    }
    for(int i=head;i!=-1;i=ne[i])v.push_back({e[i],i});
    sort(v.begin(),v.end());
    n = (int)v.size();
    for (int i = 0;i < n;i ++)
    {
        printf("%d ",v[i].first);
    }

    return 0;
}