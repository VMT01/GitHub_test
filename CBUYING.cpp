#include <iostream>
using namespace std;
unsigned long long b;
int n;
unsigned long long P[100001], C[100001];
void Enter()
{
    cin >> n >> b;
    for(int i=1;i<=n;i++)
        cin >> P[i] >> C[i];
}

void Swap(int i,int j)
{
    swap(P[i],P[j]);
    swap(C[i],C[j]);
}

void Sort(int l,int h)
{
    int i, j;
    unsigned long long k;
    if(l>=h)
        return;
    i=l;
    j=h;
    k=P[(l+h)/2];
    do
    {
        while(P[i]<k) i++;
        while(P[j]>k) j--;
        if(i<=j)
        {
            if(i<j) Swap(i,j);
            i++;
            j--;
        }
    }
    while(i<=j);
    Sort(l,j);
    Sort(i,h);
}
void Greedy()
{
    int i;
    unsigned long long j, dem;
    i=1;
    dem=0;
    for(i=1;i<=n;i++)
        if(b/P[i]>=C[i])
        {
            b-=P[i]*C[i];
            dem+=C[i];
        }
        else
        {
            dem+=b/P[i];
            break;
        }
    cout << dem;
}
int main()
{
    Enter();
    Sort(1,n);
    Greedy();
}
