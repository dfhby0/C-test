#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[110];

int main(){
    cin >> n >> d;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int maxn = a[0] + a[1];
    if(maxn > d && a[n-1] > d){
        cout << "NO";
        return 0;
    }
    else{
        cout << "YES";
        return 0;
    }

}