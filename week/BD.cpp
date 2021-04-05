#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;
ll l, r;
 

ll dfs(ll x){
    if (x == 0) return 0;
    ll m = 0, ans = 0, rest = 0;
    while (m * 2 + 1 < x) m = m * 2 + 1;
    ans = (m + 1) / 2;
    rest = x - m - 1;
    //printf("m = %lld\n", m);
    return ans + rest - (ans - dfs(m - rest)) + 1;
}

int main(){
  int t; scanf("%d", &t);
  while (t--){
    cin >> l >> r;
    printf("%lld\n", dfs(r) - dfs(l - 1));
  }
  return 0;
}