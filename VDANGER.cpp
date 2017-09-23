#include <iostream>
//#include <stdio.h>
using namespace std;
int n, m, kq,
    a[10005], F[105][105];
int main(){
//    freopen("VDANGER.inp","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> F[i][j];
    for(int t=1;t<=n;t++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                F[i][j]=min(F[i][j],F[i][t]+F[t][j]);
    kq=F[1][a[1]]+F[a[m]][n];
    for(int i=1;i<m;i++)
        kq+=F[a[i]][a[i+1]];
    cout << kq;
}
