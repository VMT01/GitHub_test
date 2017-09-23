#include <stdio.h>
#include <iostream>
#define oo 1000000007
using namespace std;
string s;
unsigned long long kq, f[1000001];
char ch[1000001];
int main()
{
    cin >> s;
    for(int i=0;i<s.size();i++)
        ch[i+1]=s[i];
    f[0]=0;
    for(int i=1;i<=s.size();i++)
    {
        f[i]=(f[i-1]*10+(ch[i]-'0')*i)%oo;
        kq=(kq+f[i])%oo;
    }
    printf("%d",kq);
}
