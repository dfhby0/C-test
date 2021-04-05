#include<bits/stdc++.h>
'''
    主要思路是找到相关联的项，这里只有前一项的顺序会影响后面
    之后确定每一步的状态数：共4种：对于每个字符串，有两个状态，因此相邻两项进行四个判断
    并在每一状态满足条件（后大于前）时记录下值 
    状态一:后一项不反转S[i][0] = min(S[i-1][0],S[i-1][1]) 
    状态二:后一项反转S[i][1] = min(S[i-1][0] + spend[i],S[i-1][1] + spend[i])
    数据过长，使用unsigned long long重新定义
'''
using namespace std;
const int N = 100010;
const int INF = 100000000000000000;
int n;
unsigned long long S[N][2],spend[N];
string s[N][2];

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        cin >> spend[i];
        S[i][0] = INF;
        S[i][1] = INF;
    }

    for(int i = 0; i < n; i ++){ 
        string temp_s;
        cin >> temp_s;
        s[i][0] = temp_s;
        reverse(temp_s.begin(),temp_s.end());
        s[i][1] = temp_s;
    }
    S[0][0] = 0;
    S[0][1] = spend[0];
    for(int i = 1; i < n; i ++){
        unsigned long long a=INF,b=INF,c=INF,d=INF;
        if(s[i][0] >= s[i-1][0] && S[i-1][0]!=INF){
            a = S[i-1][0];
            //cout<<'a'<<' '<<a<<endl;
        }
        if(s[i][0] >= s[i-1][1] &&  S[i-1][1]!=INF){
            b = S[i-1][1];
            //cout<<'b'<<' '<<b<<endl;
        }
        S[i][0] = min(a,b);
        if(s[i][1] >= s[i-1][0] && S[i-1][0]!=INF){
            c = S[i-1][0] + spend[i];
            //cout<<'c'<<' '<<c<<endl;
        }
        if(s[i][1] >= s[i-1][1] &&  S[i-1][1]!=INF){
            d = S[i-1][1] + spend[i];
            //cout<<'d'<<' '<<d<<endl;
        }
        S[i][1] = min(c,d);
        //cout << S[i][0] << ' ' << S[i][1] << endl;
    }
    int sss = -1;
    if((S[n-1][0]==INF && S[n-1][1]==INF))
        printf("%d",sss);
    else
        cout << min(S[n-1][0],S[n-1][1]) <<endl;
    
    //int ssss;
    //cin>>ssss;

    return 0;
}
