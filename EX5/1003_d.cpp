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
int min_father[MAX];
int road[MAX];
int road1[MAX];
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
