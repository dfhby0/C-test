#include <bits/stdc++.h>
using namespace std;

static int findhead(unordered_map<int,int> &m, int num){
    int k = num;
    if(m.find(num) == m.end()){
        m[num] = num;
        return num;
    }
    while(m[num] != num)
        num = m[num];
    
    while(m[k] != k){
        int cur = m[k];
        m[k] = num;
        k = cur;
    }
    return num;
}

static void judgetree(istream &cin){
    int n;
    cin>>n;
    int num1, num2;
    unordered_map<int,int> m;
    while(n > 0){
        n--;
        cin>>num1>>num2;
        int head1 = findhead(m, num1);
        int head2 = findhead(m, num2);
        if(head1 == head2){
            cout<<"NO"<<endl;
            return;
        }
        m[head1] = head2;
    }
    cout<<"YES"<<endl;

    return;
}

int main(){
    int n;
    judgetree(cin);
    cin>>n;

    return 0;
}