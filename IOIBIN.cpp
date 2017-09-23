#include <iostream>
#include <stdio.h>
using namespace std;
int n, x, y, z;
int p[10001];
void makeset()
{
    for(int i=1;i<=10000;i++)
        p[i]=-1;
}
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
    p[r1]+=p[r2];
    p[r2]=r1;
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    makeset();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x >> y >> z;
        if(z==1)
            Union(x,y);
        else
            cout << (findset(x)==findset(y)) << endl;
    }
}
