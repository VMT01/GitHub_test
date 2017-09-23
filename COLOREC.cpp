#include <iostream>
#include <stdio.h>
using namespace std;
const int t=200, maxXY=400;
int n, x, y, k, A[maxXY+1][maxXY+1], C[5][5], res;
void Enter()
{
//    freopen("COLOREC.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y,&k);
        A[x+t-1][y+t-1]=k;
    }
}
void Solve()
{
    for(int x1=0;x1<maxXY;x1++)
        for(int x2=x1+1;x2<=maxXY;x2++)
        {
            for(int i=0;i<5;i++)
                for(int j=1;j<5;j++)
                    C[i][j]=0;
            for(int y=0;y<=maxXY;y++)
                if(A[x1][y]*A[x2][y]>0)
                    if(A[x1][y]>A[x2][y])
                        C[A[x2][y]][A[x1][y]]++;
                    else
                        C[A[x1][y]][A[x2][y]]++;
            res+=C[1][2]*C[3][4]+C[1][3]*C[2][4]+C[1][4]*C[2][3];
        }
}
int main()
{
    Enter();
    Solve();
    printf("%d",res);
}
