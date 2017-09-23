#include <iostream>
#include <stdio.h>
using namespace std;
const int maxN =100001;
int n, k, A[maxN];
int64_t res;
void Enter()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> A[i];
}
void Sort(int l,int r)
{
    if(l>=r) return;
    int i=l, j=r, key=A[(l+r)/2];
    do
    {
        while(A[i]>key) i++;
        while(A[j]<key) j--;
        if(i<=j)
        {
            if(i<j) swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    Sort(l,j); Sort(i,r);
}
void Greedy()
{
    res=A[1];
    for(int i=2;i<=k+1;i++)
        res+=A[i];
    for(int i=k+2;i<=n;i++)
        res-=A[i];
}
int main()
{
    Enter();
    Sort(2,n);
    Greedy();
    cout << res;
}
