
#include <iostream>
#include <queue>
using namespace std;
int R, C, R_b, C_b, m, n, dem;
char a[101][101];
bool ktra;
int clh[4]={0,-1,0,1}, clc[4]={-1,0,1,0}, F[101][101];
struct dl
{
    int x,y;
};
void enter()
{
    cin >> R >> C;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='C')
            {
                R_b=i;
                C_b=j;
            }
        }
}
void BFS(int u, int v)
{
    queue <dl> q;
    dl c;
    c.x=u, c.y=v;
    a[u][v]='#';
    q.push(c);
    while(!q.empty())
    {
        dl u;
        u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            m=u.x+clh[i], n=u.y+clc[i];
            if(m>=1&&m<=R&&n>=1&&n<=C&&a[m][n]=='.')
            {
                F[m][n]=F[u.x][u.y]+1;
                c.x=m;
                c.y=n;
                q.push(c);
                a[m][n]='#';
                dem++;
                if(c.x==1&&c.y==1)
                {
                    ktra=true;
                    return;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    enter();
    a[1][1]='.';
    BFS(R_b,C_b);
    cout << F[1][1];
}
