//题意：有1~n种食物，k个客人，每个客人有两种喜欢的食物，这些客人按照一定顺序排队吃饭，每个人轮到的时候会吃掉自己喜欢的，如果一个都没有就不满意，问最好的排队方法可以让多少客人不满意
//思路：题解原话“Since every animal has exactly two favorite snacks, this hints that we should model the problem as a graph.”，这种题目果然还要靠经验。。一般这种事物间有相互关系的，很多都要用图的模型来表示。食物为节点，建好图之后dfs跑一下就好了。。。

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 1e5+5;

int n, k;
bool vis[MAXN];
bool gt[MAXN];

int head[MAXN], tot;
struct Edge{
    int to, next;
    int id;
}edge[MAXN*2];
void addEdge(int u, int v, int id){
    edge[++tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot;
    edge[tot].id = id;
}

void dfs(int node){
    vis[node] = true;
    for(int i = head[node]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        int id = edge[i].id;
        if(vis[v] == false){
            gt[id] = true;
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, i);
        addEdge(v, u, i);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(vis[i] == false) dfs(i);
    for(int i = 1; i <= k; ++i)
        if(gt[i] == false) ans++;
    cout << ans << endl;
    
    return 0;
} 