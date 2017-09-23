
#include <iostream>
using namespace std;
int n, m, res, a[10001], F[10001][10001];
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        F[i][a[i]]=a[i];
        F[i][0]=F[i-1][0];
        for(int j=1;j<=min(10000,m);j++)
            F[i][j]=max(F[i][j],max(F[i-1][j], F[i][j-1]));
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(m-a[i]-a[j]>=0&&F[i-1][min(10000,m-a[i]-a[j])]!=0)
                res=max(res,a[i]+a[j]+F[i-1][min(10000,m-a[i]-a[j])]);
    cout << res;
}
