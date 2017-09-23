#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, clh[4]={-1,0,1,0}, clc[4]={0,1,0,-1}, dem;
char a[101][101];
void enter()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
}
void DFS(int u, int v)
{
    a[u][v]='.';
    for(int i=0;i<4;i++)
        if((clh[i]+u<=n&&clh[i]+u>=1)&&(clc[i]+v<=m&&clc[i]+v>=1)&&a[clh[i]+u][clc[i]+v]=='#')
            DFS(clh[i]+u,clc[i]+v);
}
int main()
{
    enter();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='#')
            {
                DFS(i, j);
                dem++;
            }
    cout << dem;
}
