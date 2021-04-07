/*
鲁班大师的奇妙冒险
Description

鲁班大师在地牢里打怪兽, 现在有 33 个怪兽, 生命值分别为 l_1, l_2, l_3l 
1
​	
 ,l 
2
​	
 ,l 
3
​	
 , 这些怪兽之间可以互相营救, 即如果有怪兽被击败 (生命值为 00), 其他活着的怪兽可以对其进行复活.

已知鲁班大师的普通攻击的攻击力为 11 (每次可以攻击一个怪兽, 并使其生命值减 11), 每 77 次普通攻击会造成一定范围的 AOE 伤害 (即每个怪兽的生命值都减 11),

请问鲁班大师能否在没有怪兽被复活的情况下同时击败这 33 个怪兽?


Input
输入包含三个整数 l_1, l_2, l_3 \in [1,10^8]l 
1
​	
 ,l 
2
​	
 ,l 
3
​	
 ∈[1,10 
8
 ], 分别表示每个怪兽的生命值.


Output
如果鲁班大师可以在没有怪兽被复活的情况下同时击败这 33 个怪兽, 输出 "YES", 否则输出 "NO".


Sample Input 1 

3 2 4
Sample Output 1

YES
Sample Input 2 

10 1 7
Sample Output 2

NO
*/
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