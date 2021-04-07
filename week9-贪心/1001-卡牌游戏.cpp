/*
卡牌游戏
Description

现有 nn 张卡牌, 你可以从中抽取 mm 张, 每张卡牌的分值为该卡牌出现的次数, 求可以得到的最大的分值总和.


Input
输入包含两行, 第一行为两个正整数 n,m (1\leq m \leq n \leq 100000)n,m(1≤m≤n≤100000),

第二行为一个包含 nn 个大写字母的字符串, 每个字母表示一张卡牌.


Output
输出单独一行, 表示可以获取到的最大的分值总和.


Sample Input 1 

5 1
FACJT
Sample Output 1

1
Sample Input 2 

5 5
MJDIJ
Sample Output 2

7
*/

#include<bits/stdc++.h>
using namespace std;
int c[26]={0},b[26]={0};

int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int m,n;
    string a,aa;
    scanf("%d %d",&n,&m);
    cin >> a;

    //cout << a << endl;

    for(int i = 0 ; i < n ; i++){
        if(a[i]==' '||a[i]=='\n')break;
        //cout << a[i]-'A' << ' ' << a[i] <<  endl;
        c[a[i]-'A'] ++;
        b[a[i]-'A'] ++;
        //cout << a[i] << ' ' << c[a[i]-'A'] << ' ' << b[a[i]-'A'] << endl;
    }

    sort(c,c+26);
    sort(b,b+26);

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