#include<bits/stdc++.h>
using namespace std;
int n;
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
    cin >> m >> n;
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
        }
    }

    sort(v,v+count,cmp);
    r[count-1] = v[count-1];
    for(int i = count-2;i >= 0;i--){
        r[i] = r[i+1] + v[i];
    }

    dfs(0,0,count);

    cout <<fixed<<setprecision(2)<< maxn;

    return 0 ;
}