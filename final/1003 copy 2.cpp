#include<bits/stdc++.h>
using namespace std;
int n, m;
struct S{
    int a, b;
    int id;
}s[100010*2];
int c;
int h[100010];
int s1[100010];
int s2[100010];

void dfs(int num){
    s1[num] = 1;
    for(int i = h[num]; i != -1; i = s[i].b){
        int v = s[i].a;
        int id = s[i].id;
        if(s1[v] == 0){
            s2[id] = 1;
            dfs(v);
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        s[++c].a = v;
        s[c].b = h[u];
        h[u] = c;
        s[c].id = i;

        s[++c].a = u;
        s[c].b = h[v];
        h[v] = c;
        s[c].id = i;
    }

    int maxn = 0;
    for(int i = 1; i <= n; i ++)
        if(s1[i] == 0)dfs(i);

    for(int i = 1; i <= m; i ++)
        if(s2[i] == 0)maxn++;

    cout << maxn << endl;
    
    return 0;
} 