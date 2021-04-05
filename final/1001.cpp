#include<bits/stdc++.h>
using namespace std;
int ss[300010];
int n, m;
bool check(int x) {
    int pre;
    if (ss[1] + x >= m)pre = 0;
    else pre = ss[1];
    for (int i = 2; i <= n; i++) {
        int tmp = -1;
        if ((ss[i] + x) >= m && (ss[i] + x) % m >= pre)tmp = pre;
        else if (ss[i] <= pre&&ss[i] + x >= pre)tmp = pre;
        else if (ss[i]>pre)tmp = ss[i];
        if (tmp == -1)return false;
        pre = tmp;
    }
    return true;
}
int main() {
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>ss[i]; 
    }
    int ans = 0;
    int l = 0, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) { 
            ans = mid; 
            r = mid - 1; 
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}