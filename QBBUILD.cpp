#include <bits/stdc++.h>
using namespace std;
const long long oo=10000000;
int n, a, b, c, d, u, v, kq=oo, F[105][105];

void Floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                F[i][j]=min(F[i][j], F[i][k]+F[k][j]);
}

void solve(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            kq=min(kq, F[a][i]+F[i][b]+F[i][j]+F[j][c]+F[j][d]);
            kq=min(kq, F[a][i]+F[i][c]+F[i][j]+F[j][b]+F[j][d]);
            kq=min(kq, F[a][i]+F[i][d]+F[i][j]+F[j][b]+F[j][c]);
        }
}

int main(){
    freopen("QBBUILD.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);

    cin >> n >> a >> b >> c >> d;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            F[i][j]=(i==j?0:oo);
    while(cin >> u >> v){
        cin >> F[u][v];
        F[v][u]=F[u][v];
    }

    Floyd();
    solve();

    cout << kq;
}
