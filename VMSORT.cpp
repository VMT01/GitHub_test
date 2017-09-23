#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef map <string,int> dl;
int t, n;
dl a;
string s;
int main()
{
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        for(int j=1;j<=n;j++)
        {
            cin >> s;
            a[s]++;
        }
    }
    cout << a.size();
}
