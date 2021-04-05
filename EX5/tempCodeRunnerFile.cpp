#include<bits/stdc++.h>
using namespace std;
int n;
string temp_m;
double m;
double v[31];
double maxn = 0;
double r[31];
void dfs(int num,double value,int count){
    //cout << num <<' ' << value << ' ' << v[num]<<endl; 
    if(num==count){
        maxn = max(maxn,value);
        return;
    }
    if(value+r[num] < maxn){
        return;
    }
    if(m >= value + v[num]){
        dfs(num+1,value+v[num],count);
    }
    dfs(num+1,value,count);
}

bool cmp(double a,double b){
    return a>b;
}

int main(){
    cin >> temp_m >> n;
    int ten = 0;
    for(int i = 0;i < temp_m.size();i++){
        if(temp_m[i]=='.'){
            ten = temp_m.size() - i - 1;
        }
    }
    m = stod(temp_m);
    int count = 0;
    for(int i = 0;i < n;i ++){
        int a;
        bool flag = false;
        double total = 0;
        cin >> a;
        for(int j = 0;j < a;j ++){
            if(flag)break;
            string k;
            cin >> k;
            char temp[30];
            for(int d = 2;d < k.size();d++){
                temp[d-2] = k[d];
            }
            double temp_num = stod(temp);

            if(temp_num > 600){
                flag = true;
                break;
            }
            else{
                total += temp_num;
                if(total > 1000){
                    flag = true;
                    break;
                }
            }
        }
        if(flag==false){
            v[count] = total;
            count++;
            //cout << total << ' ';
        }
    }
    //dfs(0,0,count);
    int v_int[31];
    int ss = pow(10,ten);
    //cout << ss ;
    for(int i = 0 ;i < count;i++){
        //cout << v[i] <<' ';
        v_int[i] = int(v[i] * ss);
    }

    int kk= int(m*ss);

    int dp[count+1][kk+1];

    //cout << v_int[0] <<' ' << kk;

    //cout << count;

    for(int j = 0;j < v_int[0];j++){
        dp[0][j] = 0;
    }
    for(int j = v_int[0];j<kk;j++){
        //cout << j <<' ';
        dp[0][j] = v_int[0];
    }
    for(int i = 1;i< count ;i++){
        for(int j = 0;j<=kk;j++){
            //cout << i <<' '<< j <<' ' <<v[i] << endl; 
            if(j - v_int[i] >= 0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v_int[i]]+v_int[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int j = 0; j<=kk;j++){
        //cout << dp[count-1][j] <<' ';
        maxn = max(maxn,double(dp[count-1][j])/ss);
    }
    cout <<fixed<<setprecision(2)<< maxn;

    return 0 ;
}