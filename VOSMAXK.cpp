#include <iostream>
using namespace std;
const int maxn=1000001;
int a[maxn], n, k, i;
int64_t res, tmp, hold;
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            res+=(i-hold);
            tmp=i-hold;
        }
        else
            if(a[i]>k)
            {
                hold=i;
                tmp=0;
            }
            else res+=tmp;
    }
    cout << res;
}
