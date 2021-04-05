#include<bits/stdc++.h>
using namespace std;

int q[5010];

int find_line(int left, int right, int cut){
    if(left == right){
        if(q[left] - cut==0)return 0;
        return 1;
    }
    if(left > right)
        return 0;

    int flag = 0;
    int minn = 1000000000;
    for(int i = left; i <= right; i ++){
        if(q[i] - cut < minn){
            flag = i;
            minn = q[i] - cut;
        }
    }

    int a = min(right - left + 1,find_line(left, flag - 1, cut + minn) + find_line(flag + 1, right , cut + minn) + minn);

    return a;
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
        scanf("%d",&q[i]);
    printf("%d",find_line(0,n-1,0));

}