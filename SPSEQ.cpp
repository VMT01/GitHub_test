#include <iostream>
using namespace std;
const int maxN=100000;
int n, A[maxN+1], F1[maxN+1], F2[maxN+1], L1[maxN+1], L2[maxN+1];
void Enter(){
    int i;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> A[i];
}
int Search(int i, int j, int F[maxN+1])
{
    int l=1, r=j, k;
    while(l<r)
    {
        k=(l+r)/2;
        if(A[F[k]]<A[i])
            l=k+1;
        else r=k;
    }
    return l;
}
void Optimize()
{
    int j;
    F1[1]=1;
    L1[1]=1;
    int res=1;
    for(int i=2;i<=n;i++)
        if(A[i]>A[F1[res]])
        {
            res++;
            F1[res]=i;
            L1[i]=res;
        }
        else
        {
            j=Search(i,res,F1);
            F1[j]=i;
            L1[i]=j;
        }
    F2[1]=n;
    L2[n]=1;
    res=1;
    for(int i=n-1;i>=1;i--)
        if(A[i]>A[F2[res]])
        {
            res++;
            F2[res]=i;
            L2[i]=res;
        }
        else
        {
            j=Search(i,res,F2);
            F2[j]=i;
            L2[i]=j;
        }
}
void Escape()
{
    int i, res=0;
    for(int i=1;i<=n;i++)
        res=max(res,2*min(L1[i],L2[i])-1);
    cout << res;
}
int main()
{
    Enter();
    Optimize();
    Escape();
}
