#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int nmax = 300000+1;
int t, n, p, N;
long long a[nmax];
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    p=N=0;
    for(int i=n-1;i>=1;i--)
        if(a[i]==a[i+1])
        {
            if(++N==2)
            {
                cout << a[i]*p << endl;
                return;
            }
            p=a[i];
            a[i]=-1;
        }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cin >> t;
    for(int i=1;i<=t;i++)
        solve();
}
