/*
单链表反转
Description

反转从位置m到n的链表。请使用一趟扫描完成反转。说明:1 ≤ m ≤ n ≤链表长度。

示例:输入: 1->2->3->4->5->NULL, m = 2, n = 4

输出: 1->4->3->2->5->NULL



请用单链表的数据结构进行数据存储和算法实现


Input
输入包含两行，第一行为 3 个整数 n, a, bn,a,b (1 ≤ a ≤ b ≤ n≤ 100000)用空格隔开，第二行为 n 个整数，用空格隔开，表示链表每一个节点的值


Output
输出单独的一行，即链表反转后的结果，用空格隔开


Sample Input 1 

5 2 4
1 2 3 4 5
Sample Output 1

1 4 3 2 5
*/


#include<iostream>

using namespace std;

const int N=100010;
int e[N],ne[N];
int idx;

void init(int temp[],int n)
{
    int head = -1;
    idx = 0;
    for(int i = 0; i< n;i ++)
    {   
        idx++;
        e[i] = temp[i];
        ne[i] = idx;
    }
}

void swap(int m,int n)
{
    int t = e[m];
    e[m] = e[n];
  	e[n] = t;
}

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int temp[n];
    for (int i = 0;i < n;i++) scanf("%d",&temp[i]);
	
  	init(temp,n);
  
    for (int i = 0;i < (a+b+1)/2;i ++) swap(a-1+i,b-1-i);

    for (int i = 0;i < n;i ++) printf("%d ",e[i]);

    return 0;
}
