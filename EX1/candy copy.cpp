#include<bits/stdc++.h>
using namespace std;

const int N = 500100; 
int n,m;
int T[N],H[N],S[N];

int div_candy(){
    int k = n;

    while(k < m){
        k = k + 1;
        int p,maxn = 0;
        for(int i = 0;i < n;i ++){
            if(T[i] > maxn){
                maxn = T[i];
                p = i;
            }
        }
        T[p] = ceil((H[p]*1.0)/(S[p] + 1));
        S[p] = S[p] + 1;
    }
    int maxn = 0;
    for(int i = 0;i < n;i ++){
        if(T[i] > maxn){
            maxn = T[i];
        }
    }

    return maxn;
}

int main(){
    
    int a;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n; i ++){
        scanf("%d",&a);
        T[i] = a;
        H[i] = a;
        S[i] = 1;
    }

    printf("%d",div_candy());

    return 0;
}
