#include <iostream>
using namespace std;
const int base =31;
string a, b;
int na, nb;
long long hasht[1000001], pw[1000001], x;
long long gethash(int i)
{
    return hasht[i+nb-1]-hasht[i-1]*pw[nb];
}
int main()
{
    cin >> a >> b;
    na=a.size(), nb=b.size();
    pw[0]=1;
    for(int i=1;i<=na;i++)
    {
        pw[i]=pw[i-1]*base;
        hasht[i]=hasht[i-1]*base+a[i-1];
    }
    for(int i=1;i<=nb;i++)
        x=x*base+b[i-1];
    for(int i=1;i<=na-nb+1;i++)
        if(x==gethash(i))
            cout << i << " ";
}
