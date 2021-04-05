#include<bits/stdc++.h>
using namespace std;

int n;
double k;
int maxn = 0;
int friends[50][50];
int flag[50] = {0};
void max_friend(int thisk,int count){
    for(int i = thisk+1; i < n; i++){
        if(count + 1 + (n - 1) - i < maxn)return;
        bool sign = true;
        for(int j = 0;j < count;j++){
            if(friends[flag[j]][i]==0){
                sign = false;
                break;
            }
        }
        if(sign){
            flag[count] = i;
            max_friend(i,count+1);
        }
    }
    if(maxn < count){
        maxn = count;
        cout << endl;
    }
}

int main(){
    
    cin >> n >> k;
    for(int i = 0; i < n ; i ++)
        for(int j = 0 ; j < n ;j ++)
            cin >> friends[i][j];
    for(int i = 0;i < n; i++){
        if(n - i < maxn)break;
        flag[0] = i;
        max_friend(i,1);
    }

    printf("%.6f",(k/maxn * k/maxn) * (maxn * (maxn-1))/2);

    return 0;

}