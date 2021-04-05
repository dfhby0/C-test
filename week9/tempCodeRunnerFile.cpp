#include<bits/stdc++.h>
using namespace std;

struct N{
    long long l;
    long long r;
    int num;
};

struct l_cmp
{
    bool operator() (const N &a, const N &b) 
    {
        if(a.l==b.l)return a.r<b.r;
        return a.l < b.l;
    }
};

struct r_cmp
{
    bool operator() (const N &a, const N &b) 
    {
        if(a.r==b.r)return a.l<b.l;
        return a.r < b.r;
    }
};

priority_queue<N, vector<N>, l_cmp>ll;
priority_queue<N, vector<N>, r_cmp>rr;

int main(){
    int n;
    int l_n = 0,r_n = 0;
    cin >> n;
    for(int i = 0;i< n ; i++){
        int a,b;
        N l1,r1;
        cin>>a>>b;
        if(a>b){
            l1.l = a;
            l1.r = b;
            l1.num = i;
            ll.push(l1);
        }
        else{
            r1.l = a;
            r1.r = b;
            r1.num = i;
            rr.push(r1);
        }
    }
    
    int maxn = 0;
    int count = 0;
    N r2,l2;

    while(!ll.empty()&&!rr.empty()){
        
        r2 = rr.top();
        l2 = ll.top();
        if(r2.r >= l2.l){
            if(r2.l >= l2.l){
                maxn += r2.r;
                rr.pop();
                cout <<'1'<< endl;
            }
            else{
                maxn += r2.r;
                rr.pop();
                ll.pop();
                N temp;
                temp.l = r2.l;
                temp.r = l2.r;
                temp.num = n + count++;
                if(temp.l < temp.r){
                    rr.push(temp);
                }
                else{
                    ll.push(temp);
                }
                cout <<'2'<<  ' '<< maxn <<' ' << temp.r <<' '<< temp.l << endl;
                
            }
        }
        else{
            if(l2.r >= r2.l){
                maxn += l2.l;
                ll.pop();
                cout <<'3'<< endl;
            }
            else{
                maxn += l2.l;
                rr.pop();
                ll.pop();
                N temp;
                temp.l = r2.l;
                temp.r = l2.r;
                temp.num = n + count++;
                if(temp.l < temp.r){
                    rr.push(temp);
                }
                else{
                    ll.push(temp);
                }
                cout <<'4'<<  ' '<< maxn <<' ' << temp.r <<' '<< temp.l << endl;
            }

        }
        
    }

    while(!ll.empty()){
        N temp;
        temp = ll.top();
        maxn += temp.l;
        ll.pop();
    }

    while(!rr.empty()){
        N temp;
        temp = rr.top();
        maxn += temp.r;
        ll.pop();
    }

    cout << maxn;

    return 0;
}