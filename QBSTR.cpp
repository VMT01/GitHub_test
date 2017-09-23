#include <iostream>
using namespace std;
const int base = 10005;
string a, b;
int m, n, f[base+1][base+1];
void enter()
{
    cin >> a >> b;
    m=a.length();
    n=b.length();
}
void optimize()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
                f[i+1][j+1]=f[i][j]+1;
            else
                f[i+1][j+1]=max(f[i][j+1], f[i+1][j]);
        }
    cout << f[m][n];
}
int main()
{
    enter();
    optimize();
}
