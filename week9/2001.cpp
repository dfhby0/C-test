#include<bits/stdc++.h>
using namespace std;
int c[26]={0},b[26]={0};

int main(){
    int m,n;
    string a,aa;
    scanf("%d %d",&n,&m);
    cin >> a;
    //cout << a << endl;
    for(int i = 0 ; i < n ; i++){
        if(a[i]==' '||a[i]=='\n')break;
        //cout << a[i]-'A' << ' ' << a[i] <<  endl;
        c[a[i]-'A'] ++;
        //b[a[i]-'A'] ++;
        //cout << a[i] << ' ' << c[a[i]-'A'] << ' ' << b[a[i]-'A'] << endl;
    }

    sort(c,c+26);
    //sort(b,b+26);

    int score = 0;
    int t_num = 0;

    for(int i = 25; i >= 0 ; i--){
        if(t_num >= m)break;
        int num = 0;
        while(c[i]&&(t_num + num - m)){
            num ++;
            c[i]--;
        }
        t_num += num;
        score += num * num;
        //cout << b[i] << ' ' << num << ' ' << score << ' ' << endl;
    }
    printf("%d",score);
    //int sss;
    //cin >> sss;
    return 0;
}