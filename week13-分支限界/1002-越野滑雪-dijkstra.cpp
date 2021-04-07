/*
越野滑雪
Description

为了迎接 2022 冬奥会, Alice 投资了珠峰建雪道项目, 从峰顶出发, 可以滑雪到达山下的各个大本营,

雪道分为双板雪道和单板雪道两种, 其中,

- 双板雪道可以从峰顶到大本营, 也可以从一个大本营到另一个大本营.

- 单板雪道只能从峰顶出发到达某个大本营.

现有 nn 个大本营(包括峰顶), mm 条双板雪道, kk 条单板雪道, 为了节约成本, 在保证峰顶到各个大本营的最短路径不变的前提下, Alice 希望取消一部分单板雪道.

请问最多可以取消多少条单板雪道.


Input
输入的第一行包含三个整数 n\in [2, 100000], m\in [1, 300000], k\in [1,100000]n∈[2,100000],m∈[1,300000],k∈[1,100000],

接下来 mm 行, 分别包含三个正整数 x, y \in [1, n], x \neq y, z \in [1,10^9]x,y∈[1,n],x 
̸
​	
 =y,z∈[1,10 
9
 ], 表示 xx 到 yy 的双板雪道长度为 zz,

接下来 kk 行, 分别包含两个正整数 d, sd,s, 表示峰顶到 dd 的单板雪道长度为 ss.

（已知峰顶到每个大本营至少有一条路径, 两个大本营之间可能有多条双板雪道, 峰顶到每个大本营可能有多条路径）


Output
输出单独一行, 表示可以取消的单板雪道条数.


Sample Input 1 

3 2 2
1 2 100
2 3 1
2 1
3 3
Sample Output 1

1
Sample Input 2 

5 5 2
1 2 100
2 3 100
3 4 100
4 5 20
2 5 5
5 50
4 1
Sample Output 2

1
*/

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
