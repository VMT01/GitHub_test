#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, a, b, p[1001], dem, Enemi[1001], thu;
char k;
int findset(int u)
{
    while(p[u]>0)
        u=p[u];
    return u;
}
void Union(int u, int v)
{
    int r1=findset(u), r2=findset(v);
    if(r1==r2) return;
    if(p[r1]<p[r2])
    {
        p[r1]+=p[r2];
        p[r2]=r1;
    }
    else
    {
        p[r2]+=p[r1];
        p[r1]=r2;
    }
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    for(int i=1;i<=n;i++)
        p[i]=-1;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> k >> a >> b;
        if(k=='F') Union(a,b);
        else
        {
            if(Enemi[a]==0) Enemi[a]=b;
            else {Union(Enemi[a],b);Enemi[a]=b;}
            if(Enemi[b]==0) Enemi[b]=a;
            else {Union(Enemi[b],a);Enemi[b]=a;}
        }
    }
    for(int i=1;i<=n;i++)
        dem+=p[i]==0;
    cout << dem;
}
