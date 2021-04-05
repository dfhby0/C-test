#include<bits/stdc++.h>
using namespace std;
long long l1,l2,l3;

int main(){
    cin >> l1 >> l2 >> l3;
    long long maxn = max(max(l1,l2),l3);
    long long sum = l1 + l2 + l3;
    if(sum % 9 == 0){
        long long k=maxn/7;
        long long p=maxn%7;
        if(l1 > k && l2 > k && l3 > k){
            cout << "YES";
            return 0;
        }
        else if(p == 0 && l1 >= k && l2 >= k && l3 >= k){
            cout << "YES";
            return 0;
        }
        else{
            cout << "NO";
            return 0; 
        }
    }
    else{
        cout << "NO";
        return 0;
    }
    
}