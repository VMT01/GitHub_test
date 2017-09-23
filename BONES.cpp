#include <iostream>
using namespace std;
int n, m, i, j, k, vt, res, s1, s2, s3, d[10001];
int main()
{
    cin >> s1 >> s2 >> s3;
    for(i=1;i<=s1;i++)
        for(j=1;j<=s2;j++)
            for(k=1;k<=s3;k++)
                d[i+j+k]++;
    res=0;
    for(i=10000;i>=1;i--)
        if(d[i]>=res)
        {
            res=d[i];
            vt=i;
        }
    cout << vt;
}
