#include <bits/stdc++.h>
using namespace std;
const int nmax=1e3+1;
int n,m,a,ans,l[nmax],r[nmax],h[nmax];
int main()
{
    //freopen("QBRECT.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    h[0]=h[n+1]=-1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin >> a;
            h[j]=(a==1?h[j]+1:0);
        }
        for (int j=1;j<=n;j++)
        {
            l[j]=j;
            while (h[l[j]-1]>=h[j]) l[j]=l[l[j]-1];
        }
        for (int j=n;j>=1;j--)
        {
            r[j]=j;
            while (h[r[j]+1]>=h[j]) r[j]=r[r[j]+1];
        }
        int res=0;
        for (int j=1;j<=n;j++)
            ans=max(ans,h[j]*(r[j]-l[j]+1));//     res=h[j]*(r[j]-l[j]+1);
//        ans=max(ans,res);
    }
    cout << ans;
}
