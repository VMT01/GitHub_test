#include<stdio.h>
using namespace std;
long a,b,d=0,j;
long lat(long n)
{
    long k=0;
    while(n>0)
    {
        k=k*10+n%10;
        n/=10;
    }
    return k;
}
long gcd(long a,long b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}
int main()
{
    scanf("%ld%ld",&a,&b);
    for(long i=a;i<=b;i++)
    {
        if(i%3==0||i%11==0)
            continue;
        j=lat(i);
        if(i%2==0&&j%2==0)
            continue;
        d+=gcd(i,j)==1;
    }
    printf("%ld",d);
}
