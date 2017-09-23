#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100009;
const int oo = 2000000009;
int i, j, n, ans, tmp, b[maxn], a[maxn];
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cin >> b[i];
    sort(b+1, b+n+1);
    ans=oo;
    for(i=1;i<=n;i++)
    {
        tmp=lower_bound(b+1,b+n+1,0-a[i])-b;
        if(tmp>n) tmp=n;
        ans=min(ans, abs(a[i]+b[tmp]));
        if(tmp==1) continue;
        ans=min(ans, abs(a[i]+b[tmp-1]));
    }
    cout << ans;
}
