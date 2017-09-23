#include <iostream>
using namespace std;
const int oo=160000;
int n, C[16][16], F[1<<16][16], kq,m;
void enter()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> C[i][j];
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            F[i][j]=oo;
            F[1<<j][j]=0;
        }
    }
}
int getbit(int x, int i)
{
    return (x>>i)&1;
}
int bitoff(int x, int i)
{
    return x&=~(1<<i);
}
int main()
{
    enter();
    for(int s=1;s<(1<<n);s++){
        for(int i=0;i<n;i++)
            if(getbit(s,i)==1)
            {
                int p=bitoff(s,i);
                for(int j=0;j<n;j++)
                    if(getbit(p,j)==1&&C[j][i]>0)
                    {
                        m=min(F[s][i],F[p][j]+C[j][i]);
                        F[s][i]=m;
                    }
            }
    }
    kq=F[(1<<n)-1][0];
    for(int i=1;i<n;i++)
        kq=min(kq, F[(1<<n)-1][i]);
    cout << kq;
}
