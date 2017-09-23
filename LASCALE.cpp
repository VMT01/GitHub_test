#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long   ll;
typedef int64_t     ll;

#define readln      scanf("\n")
#define writeln     printf("\n")

ll      n, tr[20], ph[20], nt, np, a[20];

int main()
{
    scanf("%I64d",&n);
    a[0] = 1;
    for (int i=1;i<=18;i++) a[i] = a[i-1]*3;
    for (int i=0;n>0;n/=3,i++) ph[i] = n%3;
    for (int i=0;i<=17;i++) {
        if (ph[i] == 1) np++; else
        if (ph[i] == 2) nt++, tr[i] = 1, ph[i+1]++;  else
        if (ph[i] == 3) ph[i+1]++;
    }

    printf("%I64d ", nt);
    for (int i=0;i<=18;i++)
        if (tr[i] == 1) printf("%I64d ", a[i]);

    writeln;

    printf("%I64d ", np);
    for (int i=0;i<=18;i++)
        if (ph[i] == 1) printf("%I64d ", a[i]);
    return 0;
}
