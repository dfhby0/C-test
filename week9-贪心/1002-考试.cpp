/*
考试
Description

nn 个同学一起考试, 考场中只有若干圆桌, 因此同学们要围在一起考试,

为了保证考试的公平性, 两个同学之间需要保持一定的距离, 根据每个同学的视力情况, 需要保证该同学的左侧和右侧空出一定数量的座位.

每个人坐一个座位, 求最少需要多少座位(包括空出的座位).


Input
输入的第一行为一个正整数 n\in [1,100000]n∈[1,100000], 表示参加考试的同学人数,

后续 nn 行, 每行两个正整数 l,r \in [0, 10^9]l,r∈[0,10 
9
 ], 分别表示该同学左侧和右侧需要空出的座位数.


Output
输出单独的一行, 表示最少需要的座位数量.


Sample Input 1 

5
5 0
4 2
2 0
5 2
3 0
Sample Output 1

24
Sample Input 2 

3
1 1
2 2
3 3
Sample Output 2

9
*/

#include<bits/stdc++.h>
using namespace std;

struct N{
    long long l;
    long long r;
    int num;
};

struct l_cmp
{
    bool operator() (const N &a, const N &b) 
    {
        if(a.l==b.l)return a.r<b.r;
        return a.l < b.l;
    }
};

struct r_cmp
{
    bool operator() (const N &a, const N &b) 
    {
        if(a.r==b.r)return a.l<b.l;
        return a.r < b.r;
    }
};

priority_queue<N, vector<N>, l_cmp>ll;
priority_queue<N, vector<N>, r_cmp>rr;

int main(){
    int n;
    int l_n = 0,r_n = 0;
    cin >> n;
    for(int i = 0;i< n ; i++){
        int a,b;
        N l1,r1;
        cin>>a>>b;
        if(a>b){
            l1.l = a;
            l1.r = b;
            l1.num = i;
            ll.push(l1);
        }
        else{
            r1.l = a;
            r1.r = b;
            r1.num = i;
            rr.push(r1);
        }
    }
    
    long long maxn = 0;
    int count = 0;
    N r2,l2;
    while(!ll.empty()&&!rr.empty()){
        r2 = rr.top();
        l2 = ll.top();
        if(r2.r >= l2.l){
            if(r2.l >= l2.l){
                maxn += r2.r;
                rr.pop();
                //cout <<1<< ' ' << maxn <<' '<< r2.l<<' '<<r2.r <<' ' <<l2.l<<' '<<l2.r <<' ' << endl;
            }
            else{
                maxn += r2.r;
                rr.pop();
                ll.pop();
                N temp;
                temp.l = r2.l;
                temp.r = l2.r;
                temp.num = n + count++;
                if(temp.l < temp.r){
                    rr.push(temp);
                }
                else{
                    ll.push(temp);
                }
                //cout <<2<<  ' '<< maxn <<' ' << r2.l<<' '<<r2.r <<' ' <<l2.l<<' '<<l2.r <<' ' <<temp.r <<' '<< temp.l << endl;
                
            }
        }
        else{
            if(l2.r >= r2.r){
                maxn += l2.l;
                ll.pop();
                //cout <<3<< ' ' << maxn<<' '<< r2.l<<' '<<r2.r <<' ' <<l2.l<<' '<<l2.r <<' '  << endl;
            }
            else{
                maxn += l2.l;
                rr.pop();
                ll.pop();
                N temp;
                temp.l = r2.l;
                temp.r = l2.r;
                temp.num = n + count++;
                if(temp.l < temp.r){
                    rr.push(temp);
                }
                else{
                    ll.push(temp);
                }
                //cout <<4<<  ' '<< maxn <<' ' << r2.l<<' '<<r2.r <<' ' <<l2.l<<' '<<l2.r <<' ' << temp.r <<' '<< temp.l << endl;
            }

        }
        
    }

    while(!ll.empty()){
        N temp;
        temp = ll.top();
        maxn += temp.l;
        ll.pop();
    }

    while(!rr.empty()){
        N temp;
        temp = rr.top();
        maxn += temp.r;
        rr.pop();
    }

    maxn += n;
    cout << maxn;

    //int ss;
    //cin >> ss;

    return 0;
}