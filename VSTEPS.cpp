#include <iostream>
using namespace std;
const int base = 14062008;
int n, k, t, f[100001];
bool yes[100001]={true};
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        yes[i]=true;
    for(int i=1;i<=k;i++)
    {
        cin >> t;
        yes[t]=false;
    }
    f[1] = 1;
    if(yes[2])
        f[2]=1;
    else
        f[2]=0;
    for(int i=3;i<=n;i++)
        if(yes[i]==0)
            f[i]=0;
        else
            f[i]=(f[i-1]%base+f[i-2]%base)%base;
    cout << f[n];
}
