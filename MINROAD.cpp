#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int, int> pii;
const int nmax=300005;
int n, a, b, x, y, kq=1e9, s[2];
vector <pii> C;
int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        C.push_back(pii(x,y));
    }
    sort(C.begin(),C.end());
    x=-1;
    for(int i=0;i<n;++i)
    {
        if(i) --s[(C[i-1].second)&1];
        while((s[1]<a || s[0]<b) && x<n) ++s[(C[++x].second)&1];
        if(x==n) break;
        kq=min(kq,C[x].first-C[i].first);
    }
    cout << (kq==1e9?-1:kq);
}
