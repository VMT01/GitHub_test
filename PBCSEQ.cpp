#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int nmax=100000;
int n, m, b[nmax], cs;
struct dl
{
    int p, q;
} a[nmax];
void enter()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i].p >> a[i].q;
}
bool cmp(dl a, dl b)
{
    if(a.p!=b.p) return a.p>b.p;
    return a.q<b.q;
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    enter();
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cs=upper_bound(b+1,b+m+1,a[i].q)-b;
        b[cs]=a[i].q;
        m=max(m,cs);
    }
    cout << m;
}
