/*
链表旋转
Description

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2

输出: 4->5->1->2->3->NULL

解释:

向右旋转 1 步: 5->1->2->3->4->NULL

向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:

输入: 0->1->2->NULL, k = 4

输出: 2->0->1->NULL

解释:

向右旋转 1 步: 2->0->1->NULL

向右旋转 2 步: 1->2->0->NULL

向右旋转 3 步: 0->1->2->NULL

向右旋转 4 步: 2->0->1->NULL


Input
输入包含两行，第一行为 2 个整数 n, kn,k (1 ≤ k ≤ n≤ 100000)用空格隔开，第二行为 n 个整数，用空格隔开，表示链表每一个节点的值


Output
输出单独的一行，即链表旋转后的结果，用空格隔开


Sample Input 1 

5 2
1 2 3 4 5
Sample Output 1

4 5 1 2 3
Sample Input 2 

3 4
0 1 2
Sample Output 2

2 0 1
*/

#include<iostream>
using namespace std;

const int N = 100010;
int idx,n,m,head;
int e[N],ne[N];

void init()
{
    head = -1;
    idx = 0;
}

void add_tohead(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

int main()
{
    scanf("%d%d",&n,&m);
    init();
    for (int i = 0;i < n;i ++)
    {
        int v;
        scanf("%d",&v);
        if(i==0)add_tohead(v);
        else add(i,v);
    }

    int num = m % n;

    for (int i = 0;i < n;i ++)
    {
        if (i < num) printf("%d ",e[n - num + i]);
        else printf("%d ",e[i - num]);
    }

    return 0;
}
