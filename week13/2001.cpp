#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct K{
    int a;
    int b;
    long long dis;
}doub[100100];

int main(){
    cin >> n >> m >> k;
    long long road[n+1] ;
    long long road_ori[n+1] ;
    for(int i= 0 ;i<n+1;i++){
        road[i] = 1000000001;
        road_ori[i] = 1000000001;
    }
    for(int i = 0;i < m;i ++){
        cin >> doub[i].a >> doub[i].b >> doub[i].dis;
    }

    int count = 0;
    for(int i = 0;i < k;i ++){
        int a;
        long long b;
        cin >> a >> b;
        if(road_ori[a] < 1000000001){
            count ++;
        }
        if(road[a] >= b){
            road[a] = b;
            road_ori[a] = b;
        }
    }

    for(int i = 0;i < m;i ++){
        if(road[doub[i].a] + doub[i].dis <= road_ori[doub[i].b] && road_ori[doub[i].b]!=1000000001){
            road_ori[doub[i].b] = 0;
            count ++;
        }
        if(road[doub[i].b] + doub[i].dis <= road_ori[doub[i].a] && road_ori[doub[i].a]!=1000000001){
            road_ori[doub[i].a] = 0;
            count ++;
        }
    }

    cout << count;
    return 0;
}