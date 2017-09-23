#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
//#include <stdio.h>
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> pp;
int n, m, x, y, z, kq,
    h[1005];
vector <pp> v;
int findset(int u){
    if(u==h[u]) return u;
    return h[u]=findset(h[u]);
}
//void Union(int u,int v){
//    if(findset(u)!=findset(v)) return;
//    if(h[u]<h[v]){
//        h[u]+=h[v];
//        h[v]=u;
//    }
//    else{
//        h[v]+=h[u];
//        h[u]=v;
//    }
//}
int main(){
//    freopen("NKCITY.inp","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++) h[i]=i;
    while(m--){
        cin >> x >> y >> z;
        v.push_back(pp(z,pii(x,y)));
    }
    sort(v.begin(),v.end());
    int j=0;
    for(int i=0;i<v.size()&&j<n-1;i++){
        int a=findset(v[i].second.first), b=findset(v[i].second.second);
        if(a!=b){
            h[a]=b;
            kq=max(kq,v[i].first);
            j++;
        }
    }
    cout << kq;
}
