#include <iostream>
//#include <stdio.h>
using namespace std;
int n, m, a[101][101], f[101][100];
void enter()
{
  //  freopen("QBMAX.inp","r",stdin);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
}
void optimize()
{
    for(int i=1;i<=m;i++)
        f[i][1]=a[i][1];
    for(int i=1;i<=n;i++)
    {
        f[0][i]=-1000000;
        f[m+1][i]=f[0][i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=m;i++)
            f[i][j]=max(f[i-1][j-1],max(f[i][j-1],f[i+1][j-1]))+a[i][j];
    }
    int iMax=1;
    for(int i=2;i<=m;i++)
        if(f[i][n]>f[iMax][n])
            iMax=i;
    cout << f[iMax][n];
}
int main()
{
    enter();
    optimize();
}
