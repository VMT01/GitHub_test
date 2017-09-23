#include <iostream>
using namespace std;
int n, a[1001], f[1001], kq=0;
void enter()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        f[i]=1;
    }
}
void optimize()
{
    for(int i=2;i<=n;i++)
        for(int j=i-1;j>=1;j--)
            if(f[i]<f[j]+1&&a[i]>a[j])
                f[i]=f[j]+1;
    for(int i=1;i<=n;i++)
        kq=max(kq,f[i]);
    cout << kq;
}
int main()
{
    enter();
    optimize();
}
