/*
非递归方式实现二叉树的后序遍历
Description

给定一个二叉树，用非递归的方式实现二叉树的后序遍历。


Input
输入第一行为一个整数 n (1 <= n <= 100000), 表示二叉树的节点个数。

接下来共有 n 行, 每行有两个整数 l 和 r, 分别表示第 i (i为每一行的行号)个节点的左孩子和右孩子下标, 值为 0 表示当前节点没有左孩子/右孩子. 根节点的下标始终为 1.


Output
输出二叉树后续遍历的结果, 用空格分隔.


Sample Input 1 

5
2 4
5 3
0 0
0 0
0 0
Sample Output 1

5 3 2 4 1
Hint

以第一组测试用例为例, 二叉树共 5 个节点, 接下来 5 行输入,

第 1 行为 2 4, 表示节点编号为 1 的节点(根节点)的左孩子为编号为 2 的节点, 右孩子为编号为 4 的节点.

第 2 行为 5 3, 表示节点编号为 2 的节点的左孩子为编号为 5 的节点, 右孩子为编号为 3 的节点.

后续输入均为 0, 表示剩下编号为 3, 4, 5 的节点均无左/右孩子节点.
*/
#include<iostream>
using namespace std;

const int N = 100010;
int t[N],n;

int main()
{
    t[1] = 1;
    scanf("%d",&n);
    for(int i = 1; i < n + 1; i ++) 
    { 	
      if(t[i/2]!=0||i==1)scanf("%d%d",&t[i*2],&t[i*2+1]);
      else
        {
            t[i*2] = 0;
            t[i*2+1] = 0;
        }
    }

    int j = 1;
    int top = -1;
    int st[N];
    int flag,p;
    do{
        while(t[j]!=0)
        {
            top ++;
            st[top] = j;
            j = j * 2;
        }
        p = 0;
        flag = 1;
        while(top!=-1&&flag)
        {
            j = st[top];
            if((j * 2 + 1)==p || t[j * 2 + 1]==0)
            {
                printf("%d ",t[j]);
                top --;
                p = j;
            }
            else
            {
                j = j * 2 + 1;
                flag = 0;
            }
        }
    }while(top!=-1);

    return 0;
}