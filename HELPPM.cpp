#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, u, v, x1, x2, y1, y2;
long long a[501][501], sum[501][501], res, k, S, Skq;
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            u=v=1;
            while(u<=v&&v<=m)
            {
                res=sum[j][v]-sum[j][u-1]-sum[i-1][v]+sum[i-1][u-1];
                if(res<k) v++;
                else
                {
                    S=(j-i+1)*(v-u+1);
                    if(S<Skq)
                    {
                        Skq=S;
                        x1=i, x2=j, y1=u, y2=v;
                    }
                    u++;
                }
            }
        }
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    Skq=n*m+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    if(sum[n][m]<k){
        cout << -1;
        return 0;
    }
    solve();
    if(Skq==n*m-1)
    {
        cout << -1;
        return 0;
    }
    cout << Skq << '\n' << x1 << ' ' << y1 << ' '<< x2 << ' ' << y2;
}
