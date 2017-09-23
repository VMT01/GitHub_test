#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ii pair<pii, int64_t>

int n, u, v;
vector <int> dsc[10005];
vector <ii> dsk;
int64_t w, kq, nc[10005];

void DFS(int u, int ft){
    nc[u]=1;
    for(int i=0;i<dsc[u].size();i++){
        int v=dsc[u][i];
        if(v==ft) continue;
        DFS(v,u);
        nc[u]+=nc[v];
    }
}

int main(){
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> u >> v >> w;
        dsc[u].push_back(v);
        dsc[v].push_back(u);
        dsk.push_back(ii(pii(u,v),w));
    }
    DFS(0,0);
    for(int i=0;i<dsk.size();i++){
        u=dsk[i].first.first, v=dsk[i].first.second, w=dsk[i].second;
        kq+=min(nc[u],nc[v])*(n-min(nc[u],nc[v]))*w;
    }
    cout << kq;
}
