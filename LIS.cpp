#include <iostream>
#include <algorithm>
using namespace std;
int n, a[30001], f[30001], b[30001], kq=0;
void enter()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
}
void optimize()
{
    for(int i=1;i<=n;i++)
    {
        f[i]=lower_bound(b+1,b+kq+1,a[i])-b;
        kq=max(kq,f[i]);
        b[f[i]]=a[i];
    }
    cout << kq;
}
int main()
{
    enter();
    optimize();
}
