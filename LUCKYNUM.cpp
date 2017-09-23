#include <iostream>
#include <stdio.h>
using namespace std;
int t, n, l, r, f[300][300];
struct toado
{
    int x, y;
};
toado S[5000000];
int mu10(int a)
{
    int res=1;
    for(int i=1;i<=a;i++)
        res=(res*10)%n;
    return res;
}
void out(int x,int y)
{
    for(int i=1;i<=x;i++)
        printf("8");
    for(int i=1;i<=y;i++)
        printf("6");
    printf("\n");
}
void push(int x,int y)
{
    r++;
    S[r].x=x;
    S[r].y=y;
}
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(int i=0;i<=201;i++)
            for(int j=0;j<=201;j++)
                f[i][j]=-1;
        f[0][0]=0;
        l=1, r=1;
        S[1].x=0, S[1].y=0;
        int kiemtra=0;
        while(l<=r)
        {
            int x=S[l].x, y=S[l].y;
            if(x+y>0&&f[x][y]==0)
            {
                out(x,y);
                kiemtra=1;
                break;
            }
            if(y+1<=200&&f[x][y+1]==-1)
            {
                push(x,y+1);
                f[x][y+1]=(f[x][y]*10+6)%n;
            }
            if(x+1<=200&&f[x+1][y]==-1)
            {
                push(x+1,y);
                f[x+1][y]=((8*mu10(x+y))%n+f[x][y])%n;
            }
            if(x+y>200)
                break;
            l++;
        }
        if(kiemtra==0)
            printf("-1\n");
    }
}
