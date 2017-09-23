#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn=1000;
int n, k, kq, a[maxn+1][maxn+1], f[maxn+1][maxn+1];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=f[i-1][j]+f[i][j-1]+a[i][j]-f[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i<k||j<k)
                continue;
            else
                kq=max(kq,f[i][j]+f[i-k][j-k]-f[i-k][j]-f[i][j-k]);
    printf("%d",kq);
}
