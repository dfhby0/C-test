#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int l[110];
    for(int i = 1; i <= n; i++){
        scanf("%d",&l[i]);
    }

    if(n < 3 || n %2==0){
        cout << -1;
        return 0;
    }
    long long count = 0;
    while(true){
        int maxn = 0;
        int top = 0;
        for(int i = 1; i <= n ;i ++){
            if(l[i] > maxn){
                maxn = l[i];
                top = i;
            }
        }
        if(maxn==0){
            cout<<count;
            return 0;
        }
        if(top*2+1 > n)top = top/2;
        int maxn1 = max(l[top*2],l[top*2+1]);
        int maxn2;
        if(top % 2 ==0)
            maxn2 = max(l[top/2],l[top/2 * 2 + 1]);
        else{
            maxn2 = max(l[top/2],l[top/2 * 2]);
        }
        if(maxn1<maxn2 && top!=1){
            l[top/2] = max(l[top/2]-1,0);
            l[top/2 * 2] = max(l[top/2 * 2]-1,0);
            l[top/2 * 2 + 1] = max(l[top/2 * 2 + 1]-1,0);
        }
        else{
            if(maxn1==maxn2){
                int maxn1 = min(l[top*2],l[top*2+1]);
                int maxn2;
                if(top % 2 ==0)
                    maxn2 = min(l[top/2],l[top/2 * 2 + 1]);
                else{
                    maxn2 = min(l[top/2],l[top/2 * 2]);
                }
                if(maxn1 < maxn2 && top!=1){
                    l[top/2] = max(l[top/2]-1,0);
                    l[top/2 * 2] = max(l[top/2 * 2]-1,0);
                    l[top/2 * 2 + 1] = max(l[top/2 * 2 + 1]-1,0);
                }
                else{
                    l[top] = max(l[top]-1,0);
                    l[top*2] = max(l[top*2]-1,0);
                    l[top*2+1] = max(l[top*2+1]-1,0);
                }
            }          
            else{
                l[top] = max(l[top]-1,0);
                l[top*2] = max(l[top*2]-1,0);
                l[top*2+1] = max(l[top*2+1]-1,0);
            }
        }
        //cout << count << ' '<< top<<endl;
        count++;
    }

    //int ss;
    //cin >> ss;
    return 0;
}