#include<bits/stdc++.h>
using namespace std;
#define MAX 100100
#define INF 1000000010000000000
struct EdgeNode{ 
    int to;
    long long w; 
};
typedef pair<long long,int>P;
vector<EdgeNode> tmap[MAX];
long long d[MAX];
int n,m,k;
int single_road[MAX];
int min_father[MAX];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>que;
    fill(d,d + n + 1,INF);
    d[s] = 0;
    d[1] = 0;
    que.push(P(0,s));
    que.push(P(0,1));

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
    cin >> n >> m >> k;
    int r,l;
    EdgeNode e;
    fill(single_road,single_road + n + 1,0);
    fill(min_father,min_father + n + 1,0);
    long long b;
    for(int i = 0; i < m; i++){
        cin >> r >> l >> b;
        e.w = b;
        
        e.to = l;
        tmap[r].push_back(e);

        e.to = r;
        tmap[l].push_back(e);
    }
    for(int i = 0; i < k; i ++){
        cin >> r >> b;
        e.to = r;
        e.w = b;
        single_road[r]++;
        tmap[0].push_back(e);
    }
    e.to = 1;e.w = 0;
    tmap[0].push_back(e);

    dijkstra(0);
    int count = 0;
    for(int i = 2;i < n+1 ;i++){
        //cout << i << ' ' << min_father[i] << ' ' << d[i] << ' ' << single_road[i]  << endl;
        if(single_road[i]==0)continue;
        if(min_father[i]!=0)
            count += single_road[i];
        else{
            count += single_road[i] - 1;
        }
    }
    count += single_road[1];
    
    cout << count;

    //fclose(stdin);
    //system("pause");
    return 0;

}
