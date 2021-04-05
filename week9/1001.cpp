#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string m;
    int f[10];
    scanf("%d",&n);
    cin >> m;

    for(int i=1;i<10;i++)
        scanf("%d",&f[i]);
    
    int flag = 1;
    int i = 0;
    while(flag && i<n){
        int num = m[i] - '0';
        //cout << num <<' '<<f[num]<<endl;
        if(flag == 2 && f[num] < num)
            break;
        if(f[num] > num){
            flag = 2;
            m[i] = f[num] + '0';
        }
        i ++;
    }
    cout << m;
    return 0;
}