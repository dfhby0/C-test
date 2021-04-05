#include<bits/stdc++.h>
using namespace std;

const int N = 500100; 
int n,m;
int H[N];

int div_candy(){
    int k = n;
    int p,maxn=0;
    for(int i = 0;i < n;i ++){
        if(H[i] > maxn){
            maxn = H[i];
            p = i;
        }
    }
    int low = 0,mid;
    int high = maxn;
    while(high - low > 1){
        p = 0;
        mid = ceil((high + low)*1.0/2);
        for(int i = 0;i < n;i ++)
            if(H[i]<=mid)p ++;
            else{
                p = p + ceil((H[i]*1.0)/mid);
            }

        cout<< high <<' '<<  mid<<' '<< low<< ' '<< p << endl;

        if(p == m)
            return mid;
        else if(p>m)
            low = mid;
        else
            high = mid;
    }
    if(p < m)
        return mid;
    else
        return mid + 1;

}

int main(){
    
    int a;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n; i ++){
        scanf("%d",&a);
        H[i] = a;
    }
    
    printf("%d",div_candy());

    int ss;
    scanf("%d",&ss);

    return 0;
}
