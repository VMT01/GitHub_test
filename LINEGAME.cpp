#include <iostream>
using namespace std;
const int maxn=1000000;
int n;
long long a[maxn+1], F[maxn+1][2];
void enter()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        F[i][0]=max(F[i-1][1]+a[i],F[i-1][0]);
        F[i][1]=max(F[i-1][0]-a[i],F[i-1][1]);
    }
    cout << max(F[n][0],F[n][1]);
}
int main()
{
    enter();
    solve();
}
