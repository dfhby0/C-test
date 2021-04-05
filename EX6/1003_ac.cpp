#include<bits/stdc++.h>
using namespace std;
const int maxn=80;
typedef long long ll;
long long f[2][maxn][maxn][maxn];
int a[maxn][maxn];
int n,m,k;
int main () {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    memset(f,-1,sizeof(f));
    f[1][0][0][0]=0;
    int F=1;
    for (int i=1;i<=n;i++,F^=1) 
        for (int j=0;j<m;j++) 
            for (int l=0;l<=min(j+1,m/2);l++) {
                for (int r=0;r<k;r++) {
                    f[F][j+1][l][r]=max(f[F][j+1][l][r],f[F][j][l][r]);
                    if (l&&f[F][j][l-1][r]!=-1) {
                        f[F][j+1][l][(r+a[i][j+1])%k]=max(f[F][j+1][l][(r+a[i][j+1])%k],f[F][j][l-1][r]+a[i][j+1]);
                     }
                }
                for (int r=0;r<k;r++) f[F^1][0][0][r]=max(f[F^1][0][0][r],f[F][j+1][l][r]);
    }
    printf("%lld\n",max(0ll,f[F][0][0][0]));
}