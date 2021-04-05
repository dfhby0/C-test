#include<bits/stdc++.h>
using namespace std; 
int nums[21];
int n;

bool backtrack(int num, int total, int side[]) {
        if (num == n) {
            return (side[0] == side[1] && side[1] == side[2] && side[2] == side[3]);
        }
        for (int i = 0; i < 4; i++) {
            if (side[i] + nums[num] > total) {
                continue;
            }
            side[i] += nums[num];
            if (backtrack(num + 1, total, side)) {
                return true;
            }
            side[i] -= nums[num];
        }

        return false;
    }

bool cmp(int a,int b){
    return a>b;
}

bool issquare(){
    int sum = 0;
    for(int i = 0;i<n;i++)sum=sum+nums[i];
    if (sum % 4 != 0) {
        return false;
    }
    int side_long = sum / 4;
    int side[4] = {0};
    return backtrack(0, side_long, side);
}
 
int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i ++)cin>>nums[i];
    sort(nums,nums+n,cmp);
    if (issquare() == true)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}