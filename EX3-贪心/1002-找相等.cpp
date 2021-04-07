/*
找相等
Description

给定一组数 a_1, a_2, \cdots, a_na 
1
​	
 ,a 
2
​	
 ,⋯,a 
n
​	
 , 对于这组数, 每一轮可以执行如下任意一个操作:

选取当前这些数中最小的一个并将其加 11;
选取当前这些数中最大的一个并将其减 11.
求最少的轮数使得最终得到的一组数中至少有 kk 个数的值相等.


Input
输入包含两行, 第一行为两个正整数 n, k (1\leq k \leq n \leq 200000)n,k(1≤k≤n≤200000),

第二行包含 nn 个正整数 a_1, a_2, \cdots, a_n \in [1, 10^9]a 
1
​	
 ,a 
2
​	
 ,⋯,a 
n
​	
 ∈[1,10 
9
 ].


Output
输出单独一行, 表示最少要执行的轮数.


Sample Input 1 

6 3
1 10 10 10 10 20
Sample Output 1

0
Sample Input 2 

7 5
3 3 2 1 1 1 3
Sample Output 2

4
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
   	unsigned long long nums[200020];
    
    //freopen("18.in","r",stdin);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if(n<2 || k==1){
        cout<< 0;
        return 0;
    }

    sort(nums,nums+n);

    long long same_num = 1;
    for(int i = 1; i < n; i++) {
        if(nums[i]==nums[i-1]){
            same_num ++;
        }
        else{
            same_num = 1;
        }
        if(same_num == k){
            cout << 0;
            return 0;
        }
    }

    int mid = n/2;
    long long mid_count = 1;

    int j = mid-1;
    while(nums[j]==nums[mid]){
        mid_count++;
        j--;
    }
    j = mid+1;
    while(nums[j]==nums[mid]){
        mid_count++;
        j++;
    }

    if(mid > k - mid_count){
        int lm = k - 1;
        int rm = n - k;
        int left_count = 0;
        j = lm+1;
        while(nums[j]==nums[lm]){
            left_count++;
            j++;
        }

        int right_count = 0;
        j = rm-1;
        while(nums[j]==nums[lm]){
            right_count++;
            j--;
        }
        long long left_num = 0;
        for(int i = 0;i < lm;i++){
            left_num += nums[lm] - nums[i];
        }
        long long right_num = 0;
        for(int i = n-k+1;i < n;i++){
            right_num += nums[i] - nums[rm];
            //cout <<'1' << ' '<< nums[i] << ' ' << right_num << ' ' << nums[rm] << endl;
        }

        //cout <<'1' << ' '<< right_num << ' ' << left_num << ' ' << nums[rm] << ' '<<nums[lm] <<' ' << mid_count << endl;
        cout << min(right_num-right_count,left_num-left_count);
        //int ss;
        //cin>>ss;
        //fclose(stdin);
        return 0;
    }
    else{
        int num;
        unsigned long long mid_num;
        if(n % 2 == 0)
        {
            num = n / 2;
            mid_num = (nums[mid-1] + nums[mid])/2;
        }
        else
        {
            num = n / 2;
            mid_num = nums[mid];
        }
        unsigned long long left_num = 0;
        for(int i = 0;i <= num;i++){
            left_num += mid_num - nums[i];
        }
        unsigned long long right_num = 0;
        for(int i = n - num;i < n;i++){
            right_num += nums[i] - mid_num;
        }
        //cout <<'2' << ' '<< left_num << ' ' << right_num << ' ' <<mid_num<<endl;

        cout << left_num + right_num - (n - k);

        //int ss;
        //cin>>ss;
        //fclose(stdin);
        return 0;
    }
}