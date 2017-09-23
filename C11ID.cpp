#include <iostream>
using namespace std;
const long long k=10e8+1;
int n;
long long a[100001], nho;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        nho=(a[i]-i+1)%k;
        a[i]=nho;
    }
    nho=a[1];
    for(int i=2;i<=n;i++)
        nho=(nho*a[i])%k;
    cout << nho;
}
