/*
判断无向图G是否是一棵树
Description

给定一个无向图 G, 判断 G 是否为一棵树, 如果是, 输出 "YES", 否则输出 "NO".


Input
输入的第一行为一个正整数 n, 表示图中边的数量.

接下来 n 行输入, 每行为两个正整数 a, b, 表示节点 a 到节点 b 存在一条边.


Output
输出单独的一行, 如果给定无向图是一棵树, 输出 "YES", 否则输出 "NO".


Sample Input 1 

5
1 2
1 5
2 3
3 6
3 4
Sample Output 1

YES
Sample Input 2 

5
1 2
1 3
2 5
3 4
4 5
Sample Output 2

NO
*/

#include<bits/stdc++.h>
using namespace std;
static const int N = 100010;

unordered_map<int,queue<int>>que;
int M[N];
int num = 0;
int test_num = 0;
int edge = 0;

void dfs(int a)
{
    int b;
    while(!que[a].empty())
    {
        M[a] = 1;
        if(!M[que[a].front()])
        {
            edge ++;
            b = que[a].front();
            //printf("%d-%d ",a,b);
            que[a].pop();
            dfs(b);
        }
        else
        {
            que[a].pop();
        }
    }
}

int main()
{
    memset(M,0,sizeof(M));
    int n;
    int a,b;
    int oa,ob;
    scanf("%d",&n);
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        scanf("%d%d",&a,&b);
        if(que[a].size()==0)num++;
        if(que[b].size()==0)num++;
        que[a].push(b);
        que[b].push(a);
    }
    
    dfs(a);

    for(int i = 0;i<N;i++)
    {
        if(M[i]!=0)test_num++;
    }
    if(edge==n&&test_num==num)printf("YES");
    else printf("NO");

    return 0;
}