#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, A[20001];
void Enter()
{
//    freopen("NOIXICH.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
}
void Swap(int i,int j)
{
    int tmp=A[i];
    A[i]=A[j]; A[j]=tmp;
}
void Sort(int l,int h)
{
    int i, j, k;
    if(l>=h)
        return;
    i=l;
    j=h;
    k=A[(l+h)/2];
    do
    {
        while(A[i]<k)   i++;
        while(A[j]>k)   j--;
        if(i<=j)
        {
            if(i<j) Swap(i,j);
            i++;
            j--;
        }
    }
    while(i<j);
    Sort(l,j);
    Sort(i,h);
}
void Solve()
{
    int i=1;
    m=0;
    while(n>1)
    {
        if(A[i]>n-1)
            break;
        m+=A[i];
        n-=A[i]+1;
        i++;
    }
    m+=n-1;
}
int main()
{
    Enter();
    Sort(1,n);
    Solve();
    printf("%d",m);
}
