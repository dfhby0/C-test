/*
莱乌网络
Description

国内有若干个城市, 不同城市之间由公路连接,为了提升快递效率, 莱乌网络在全国建立了若干个仓库, 已知每个仓库到其总部的最短距离均为dd. 作为竞争对手, 川三网络想要知道莱乌网络的仓库数量.

根据上述条件,请你帮忙计算, 莱乌网络最多有多少个仓库.

(仓库可能建在城市, 也可能建在公路上).


Input
输入的第一行为三个正整数, n \in [2,100000], m\in [n-1, 100000], s\in [1,n], d\in [1,10^9]n∈[2,100000],m∈[n−1,100000],s∈[1,n],d∈[1,10 
9
 ], 分别表示城市数量, 公路数量, 莱乌网络的总部所处城市编号以及总部到仓库的最短距离.

后续 mm 行, 每行三个整数, u, v, lu,v,l, 其中 u,v \in [1,n], l \in [1,1000]u,v∈[1,n],l∈[1,1000]. u,vu,v 表示由当前公路相连的城市编号, ll 表示公路的长度.

保证任意两个城市之间都可达, 每条路都连接两个不同的城市, 两个城市之间最多只有一条公路直达.


Output
输出单独一行, 表示莱乌网络最多可能的仓库数量.


Sample Input 1 

3 3 3 144
2 1 199
3 1 819
3 2 917
Sample Output 1

2
Sample Input 2 

5 6 3 4
3 1 1
3 2 1
3 4 1
3 5 1
1 2 6
4 5 8
Sample Output 2

3
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100100
#define INF 1000000010000000000
struct EdgeNode{ 
    int to;
    long long w;
    int sign; 
};
typedef pair<long long,int>P;
vector<EdgeNode> tmap[MAX];
long long d[MAX];
int n,m,k;
int single_road[MAX];
int min_father[MAX];
long long dd;

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>que;
    fill(d,d + n + 1,INF);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < tmap[v].size();i ++){
            EdgeNode e = tmap[v][i];
            if(d[e.to] >= d[v] + e.w){
                d[e.to] = d[v] + e.w;
                que.push(P(d[e.to],e.to));
                if(v!=0)min_father[e.to] = v;
            }
        }
    }
}

int road[100010];
int road1[100010];
int main(){
    //freopen("19.in","r",stdin);
    cin >> n >> m >> k >> dd;
    int r,l;
    EdgeNode e;
    fill(road,road + m + 1,0);
    fill(road1,road1 + m + 1,0);
    long long b;
    for(int i = 0; i < m; i++){
        cin >> r >> l >> b;
        e.w = b;
        e.sign = i;

        e.to = l;
        tmap[r].push_back(e);

        e.to = r;
        tmap[l].push_back(e);
    }

    dijkstra(k);
    int count = 0;
    for(int i = 1;i < n;i++){
        if(d[i] == dd)count ++;
        else if(d[i] < dd){
            for(int j = 0;j < tmap[i].size();j++){
                if(tmap[i][j].w + d[i] > dd && d[tmap[i][j].to] + tmap[i][j].w > dd && road[tmap[i][j].sign]==0){
                    if(d[tmap[i][j].to] < dd){
                        if(tmap[i][j].w + d[tmap[i][j].to] +d[i] == 2*dd)
                            count = count + 1;
                        else{
                            count = count + 2;
                        }
                    }
                    else if(d[tmap[i][j].to] > dd){
                        count = count + 1;
                    }
                    road[tmap[i][j].sign] = 1;
                }
            }
        }
    }

    cout << count;

    //fclose(stdin);
    //system("pause");
    return 0;

}
