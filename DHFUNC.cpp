//only 85.71
#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
const int max_id = 501;
ull x, y, a, b, m, fib[max_id], f[max_id][max_id];
inline ull gcd(ull a, ull b)
{
    return (a?gcd(b%a,a):b);
}
ull fmul(ull a, ull b)
{
    if (!b) return 0;
    if (!(b-1)) return a;
    if (b%2)
        return (fmul(a, b/2)*2+a)%m;
    else
        return (fmul(a, b/2)*2)%m;
}
void dhfunc()
{
    scanf("%d%d%d%d%d",&x,&y,&a,&b,&m);
    int i, j;
    fib[1] = 1; fib[2] = 1;
    for (i=3; i < max_id; i++) fib[i] = (fib[i-1]+fib[i-2])%m;
    for (i=0; i <= x; i++) f[i][0] = i%m;
    for (i=0; i <= y; i++) f[0][i] = i%m;
    for (i=1; i <= x; i++)
        for (j=1; j <= y; j++)
            f[i][j] = (fmul(a, f[i-1][j])+fmul(b, f[i][j-1])+fib[gcd(i, j)])%m;
    printf("%d\n",f[x][y]);
}
int main()
{
    short t;
    scanf("%d",&t);
    while (t--)
        dhfunc();
}
