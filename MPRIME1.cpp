#include <iostream>
#include <cmath>
using namespace std;
int a[11001],t=1, bd=2, n;
bool ktnt(int x)
{
    if(x<2) return false;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
void xuly(int n)
{
    int d=0;
    while (a[t-1]<=n)
    {
        bd++;
        if(ktnt(bd)) a[t++]=bd;
    }
    int s,j;
    for(j=0;j<t;j++)
    {
        int i=j;
        s=a[i];
        while (s<n)
        {
            i++;
            s+=a[i];
        }
        if(s==n) d++;
    }
    cout << d << '\n';
}
int main()
{
	a[0]=2;
    do
    {
        cin >> n;
        if(n!=0) xuly(n);
    }
    while (n!=0);
}
