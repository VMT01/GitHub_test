#include <iostream>
using namespace std;
int l, r, a[100001], d=0;
int main()
{
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> r;
    for(int i=1;i<=r;i++)
        a[i]=1;
    for(int i=2;i<=r;i++)
        for(int j=2*i;j<=r;j+=i)
            a[j]+=i;
    for(int i=l;i<=r;i++)
        d+=a[i]>i;
    cout << d;
}
