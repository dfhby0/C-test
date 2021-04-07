/*
抢答
Description

Alice 参加答题活动，活动形式为抢答，

题目给出一个数字 nn，Alice 需要回答一个不小于 nn 的最小正整数(十进制)，该正整数要满足如下要求：

只包含 44 和 77
44 和 77 的个数相等
请你尽可能快的帮 Alice 计算出该数字.


Input
输入一个正整数 n \in [1, 10^{100000}]n∈[1,10 
100000
 ].


Output
输出单独一行, 表示题目要求的不小于 nn 的最小正整数


Sample Input 1 

47
Sample Output 1

47
Sample Input 2 

4666
Sample Output 2

4747
*/
#include<bits/stdc++.h>
using namespace std;

char com_4_7(char x){
    if(x > 7)
        return '0';
    else if(x>4)
        return '7';
    else return '4';
}

int main()
{
    string nums;
    cin >> nums;
    int n = nums.size();
    char res_nums[100010];
    res_nums[0] = '0';

    for(int i = n-1; i >=0 ; i--){
        char temp = com_4_7((nums[i]-'0')+(res_nums[n-i-1]-'0'));
        //cout << nums[i] <<' ' <<res_nums[n-i-1]<< ' ' << (nums[i]-'0')+(res_nums[n-i-1]-'0') <<endl;
        if(temp =='0'){
            res_nums[n-i] = '1';
            res_nums[n-i-1] = '4';
        }
        else{
            res_nums[n-i] = '0';
            //cout << temp << ' ';
            res_nums[n-i-1] = temp;
        }
    }

    if(res_nums[n]=='1'){
        res_nums[n] = '4';
        n = n + 1;
    }

    if(n % 2 == 1){
        res_nums[n] = '4';
        n = n + 1;
    }

    int count = 0;
    int n1 = nums.size();
    if(n>n1){
        count = 1;
        for(int k = 1;k < n;k++){
            if(count>=n/2){
                if(res_nums[n-1-k]=='4')
                    res_nums[n-1-k]='7';
            }
            else{
                res_nums[n-1-k]='4';
                count++;
            }  
        }
        for(int i = n-1;i>=0;i--){
            cout << res_nums[i];
        }
        return 0;
    }

    //cout<< n << endl;
    //cout << count << endl;
    //cout << res_nums <<' '<<nums <<endl;

    int i = n - 1;
    int j = 0; 
    count = 0;
    while(i >= 0){
        //cout << i << ' '<< j << ' ' <<count1 <<' '<< count << endl;
        if(res_nums[i] != nums[j]){
            for(int k = i-1; k >=0 ;k--){
                res_nums[k] = '4';
            }
            break;
        }
        i--;
        j++;
    }

    for(int i = n - 1;i >= 0; i --){
        if(count==n/2){
            res_nums[i] = '7';
            continue;
        }
        if(res_nums[i]=='4')
            count++;    
    }

    if(count == n/2){
        for(int i = n-1;i>=0;i--){
            cout << res_nums[i];
        }
        return 0;
    }
    else{
        int i = 0;
        int j = n1 - 2; 
        int count1 = 0;
        while(i < n-1){
            //cout << i << ' '<< j << ' ' <<count1 <<' '<< count << endl;
            if(count==n/2){
                for(int i = n-1;i>=0;i--){
                    cout << res_nums[i];
                }
                return 0;
            }
            if(j >= 0 && res_nums[i] == '7'){
                count1++;
                if(nums[j] == '7' && res_nums[i+1]=='7'){
                    j--;
                    i++;
                }
                else{
                    if((count1 + count) >= n/2){
                        int kk1 = n-1,kk2 = 0;
                        while(kk1>i+1){
                            if(res_nums[kk1]!=nums[kk2])break;
                            kk1--,kk2++;
                        }
                        if(kk1!=i+1){
                            for(int k = kk1-1;k>=0;k--){
                                if(count==n/2){
                                    for(int i = n-1;i>=0;i--){
                                        cout << res_nums[i];
                                    }  
                                    return 0;
                                }
                                if(res_nums[k]=='7'){
                                    res_nums[k]='4';
                                    count++;
                                    //cout << count << ' '<< k << endl;
                                }
                            }
                        }
                        if(res_nums[i+1]!='7'){
                            res_nums[i+1] = '7';
                            count--;
                        }
                        for(int k = i;k>=0;k--){
                            if(count==n/2){
                                for(int i = n-1;i>=0;i--){
                                    cout << res_nums[i];
                                }  
                                return 0;
                            }
                            if(res_nums[k]=='7'){
                                res_nums[k]='4';
                                count++;
                                //cout << count << ' '<< k << endl;
                            }
                        }
                        for(int i = n-1;i>=0;i--){
                            cout << res_nums[i];
                        }
                        return 0;
                    }
                    j--;
                    i++;
                }
            }
            else{
                j--;
                i++;
            }
        }
        n = n + 2;
        res_nums[n-1] = '4';
        res_nums[n-2] = '4';
        count = count+2;
        if(count==n/2){
            for(int i = n-1;i>=0;i--){
                cout << res_nums[i];
                return 0;
            }
        }
        for(int k = 2;k < n-1;k++){
            if(count==n/2){
                for(int i = n-1;i>=0;i--){
                    cout << res_nums[i];
                    return 0;
                }
            }
            if(res_nums[n-1-k]=='7'){
                res_nums[n-1-k]='4';
                count++;
            }
        }
    }
    return 0;
}