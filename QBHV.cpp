#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char s[10];
int n;
bool cmp(char a, char b)
{
    return a<b;
}
vector <string> a;
int main()
{
    ios_base::sync_with_stdio("false");
    cout.tie(NULL);
    while(cin >> s[n])
        n++;
    sort(s,s+n,cmp);
    do
        a.push_back(s);
    while(next_permutation(s,s+n));
    cout << a.size();
    for(int i=0;i<a.size();i++)
        cout << '\n' << a[i];
}
