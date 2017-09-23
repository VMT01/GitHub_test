#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
//#include <stdio.h>
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> pp;
vector <pp> v;
int n, m, x, y, z, kq,
    h[10005];
int findset(int u){
    if(u==h[u]) return u;
    return h[u]=findset(h[u]);
}
int main(){
//    freopen("NKRACING.inp","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++) h[i]=i;
    while(m--){
        cin >> x >> y >> z;
        kq+=z;
        v.push_back(pp(z,pii(x,y)));
    }
    sort(v.begin(),v.end());
    int j=0;
    for(int i=v.size()-1;i>=0 && j<n-1;i--){
        int a=findset(v[i].second.first), b=findset(v[i].second.second);
        if(a!=b){
            h[a]=b;
            kq-=v[i].first;
            j++;
        }
    }
    cout << kq;
}

