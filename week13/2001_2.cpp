#include<bits/stdc++.h>
using namespace std;
#define M 200010  //有几个0就是10的几次方
#define N 100010

struct edge
{
	int x, y, w;
	bool operator <(edge e)
	{
		return w < e.w;
	}
};
edge e[M + 5];

struct node
{
	int parent;
	bool root;
	node()
	{
		parent = 1;
		root = true;
	}
};
node v[N + 5];

int find(int a)
{
	while(v[a].root != true)
		a = v[a].parent;
	return a;
}

void unite(int a, int b)
{
	if(v[a].parent > v[b].parent)  //将元素少的树并到元素多的树上
	{
		v[b].root = false;
		v[a].parent += v[b].parent;
		v[b].parent = a;
	}
	else
	{
		v[a].root = false;
		v[b].parent += v[a].parent;
		v[a].parent = b;
	}
}


int main()
{
	int n, m;
	sort(e, e + m);
	int cnt = 0;
	for(int i = 0; i < m; ++i)
	{
		int u = find(e[i].x);
		int v = find(e[i].y);
		if(u != v)
		{
			++cnt;
			unite(u, v);
			//选中了e[i]这条边
			
			if(cnt == n - 1) break;
		}
	}
	if(cnt < n - 1) ;   //不连通
	else ;              //连通
	return 0;
}