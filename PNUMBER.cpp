#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int prime[b+1];
    prime[0]=prime[1]=0;
    int i, j;
    for(i=2;i<=b;i++)
    {
        if(i>2&&i%2==0)
            prime[i]=0;
        else
            prime[i]=1;
    }
    i=3;
    while(i<=b/2)
    {
        for(j=2;i*j<=b;j++)
            prime[i*j]=0;
        do
        {
            i+=2;
        }
        while(!prime[i]);
    }
    for(int i=a;i<=b;i++)
        if(prime[i])
            cout << i << endl;
    return 0;
}
