/*
数组元素替换
Description

有 nn 个由正整数构成的数组 a_1, \cdots, a_na 
1
​	
 ,⋯,a 
n
​	
 , 每一轮可以选择三个两两不等的下标 i, j, ki,j,k, 并且令 a_i = a_j + a_ka 
i
​	
 =a 
j
​	
 +a 
k
​	
 .

请问是否可以通过上述操作 (不限次数) 使得所有 a_ia 
i
​	
  不大于一个目标值 dd?


Input
输入的第一行为两个正整数 n \in [3,100], d\in [1,100]n∈[3,100],d∈[1,100], 分别表示数组中元素的数量以及目标值 dd.

第二行包含 nn 个正整数 a_1, \cdots, a_n \in [1,100]a 
1
​	
 ,⋯,a 
n
​	
 ∈[1,100], 表示数组中每个元素的值.


Output
如果存在一系列操作使得所有 a_ia 
i
​	
  不大于一个目标值 dd, 输出 "YES", 否则输出 "NO".


Sample Input 1 

3 1
1 1 1
Sample Output 1

YES
Sample Input 2 

3 1
2 1 1
Sample Output 2

NO
*/

#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[110];

int main(){
    cin >> n >> d;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int maxn = a[0] + a[1];
    if(maxn > d && a[n-1] > d){
        cout << "NO";
        return 0;
    }
    else{
        cout << "YES";
        return 0;
    }

}