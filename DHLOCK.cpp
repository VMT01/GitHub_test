#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn=300;
int n, k, kiluc, kq, tam, a[maxn+1], b[maxn+1], c[maxn+1];
void enter()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
}
void solve()
{
    for(int kk=0;kk<n;kk++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+kk>n)          tam=(i+kk)%n;
            else                tam=i+kk;
            if(b[tam]>=a[i])    c[i]=b[tam]-a[i];
            else    c[i]=b[tam]+k-a[i]+1;
        }
        for(int i=1;i<=n;i++)
        {
            kq=0;
            tam=c[i];
            for(int j=1;j<=n;j++)
                if(c[j]>=tam)
                    kq+=(c[j]-tam);
                else
                    kq+=(c[j]+k-tam+1);
                if(kq+kk+tam<kiluc)
                    kiluc=kq+kk+tam;
        }
    }
}
void init()
{
    for(int i=1;i<=n;i++)
        if(b[i]>=a[i])
            kiluc+=(b[i]-a[i]);
        else
            kiluc+=(b[i]+k-a[i]+1);
}
int main()
{
    enter();
    init();
    solve();
    printf("%d",kiluc);
}
