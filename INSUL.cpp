//100đ
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn=100000;
int n, a[maxn], kq;
void enter()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        kq+=a[i];
    }
}
void solve()
{
    sort(a,a+n);
    int i=0, j=n-1;
    while(i<j)
    {
        kq+=(a[j]-a[i]);
        i++;
        j--;
    }
    printf("%ld",kq);
}
int main()
{
    enter();
    solve();
}
