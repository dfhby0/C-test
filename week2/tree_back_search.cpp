#include<iostream>
using namespace std;

const int N = 100010;
int t[N],n;

int main()
{
    t[1] = 1;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&t[i*2],&t[i*2+1]);

    int j = 1;
    int top = -1;
    int st[N];
    int flag,p;

    do{
        while(t[j]!=0)
        {
            top ++;
            st[top] = j;
            j = j * 2;
        }
        p = 0;
        flag = 1;
        while(top!=-1&&flag)
        {
            j = st[top];
            if(t[j * 2 + 1]==0)
            {
                printf("%d ",t[j]);
                top --;
                p = j;
            }
            else
            {
                j = j * 2 + 1;
                flag = 0;
            }
        }
    }while(top!=-1);
    return 0;
}



