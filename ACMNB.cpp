#include <iostream>
#include <algorithm>
using namespace std;
const int nmax=800005;
typedef pair <int, int> pii;
int n, kq;
pii C[nmax];
bool cmp(pii a, pii b){
    return a.first-a.second < b.first-b.second;
}
int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=2*n;i++)
        cin >> C[i].first >> C[i].second;
    sort(C+1,C+2*n+1,cmp);
    for(int i=1;i<=n;i++) kq+=C[i].first;
    for(int i=n+1;i<=2*n;i++) kq+=C[i].second;
    cout << kq;
}
