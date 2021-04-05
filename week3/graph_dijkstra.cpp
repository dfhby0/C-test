#include<bits/stdc++.h>
using namespace std;

static const int N = 10010;
static const int INFTY = (1<<20);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

vector<pair<int,int>>adj[N];

int n;

void dijkstra()
{
    priority_queue<pair<int,int>>PQ;
    int color[N];
    int d[N];
    for( int i = 1; i < n + 1; i ++)
    {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[1] = 0;
    PQ.push(make_pair(1,1));
    color[1] = GRAY;

    while(!PQ.empty())
    {
        pair<int, int> f = PQ.top();PQ.pop();
        int u = f.first;

        color[u] = BLACK;

        //printf("%d--%d\n",u,d[u]);

        if( d[u] < f.second * (-1)) continue;

        for( int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].first;
            //printf("--%d-%d\n",v,d[v]);
            if ( color[v] == BLACK) continue;
            if ( d[v] > d[u] + adj[u][j].second )
            {
                d[v] = d[u] + adj[u][j].second;
                //printf("%d-%d-%d\n",u,v,d[v]);
                PQ.push(make_pair(v , d[v]* (-1)));//优先队列优先较大值
                color[v] = GRAY;
            }
        }
    }

    int maxn = 0;
    for ( int i = 1; i < n + 1; i++)
    {   
        //printf("%d ",d[i]);
        maxn += d[i];
    }
    cout << maxn << endl;
}

int main()
{
    int k, u, v;

    cin>>n;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> u >> v;
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));
    }

    dijkstra();

    return 0;
}

