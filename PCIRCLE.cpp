#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n, d=0;
int kq[10]={0,1,2,2,4,96,1024,2880,81024,770144};
int nt[38]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
int cx[20];
int x[20];
void ghi()
{
    printf("\n");
    for(int i=1;i<=2*n;i++)
        printf("%i ",x[i]);
    d++;
}
void Try(int i)
{
    for(int j=2;j<=2*n;j++)
        if(nt[j+x[i-1]]==1&&cx[j]==0)
        {
            cx[j]=1;
            x[i]=j;
            if(i==2*n&&nt[x[2*n]+1]==1)
            {
                ghi();
                if(d==10000)
                    exit(0);
            }
            else
                Try(i+1);
            cx[j]=0;
        }
}
int main()
{
    x[1]=1;
    cin >> n;
    cout << kq[n];
    Try(2);
}
