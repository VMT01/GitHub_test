#include <bits/stdc++.h>
using namespace std;
const long long oo=LONG_LONG_MAX;
#define pii pair<int, long long>
int n, m, k, u, v, du, uv;
long long w, d[5005], T[5005];
vector <pii> adj[5005];
//bool cx[5005];

void IJK(){
    for(int i=1;i<=n;i++) d[i]=oo;
    d[1]=0, T[1]=1;
    priority_queue <pii> pq;
    pq.push(pii(1,0));
//    cx[1]=true;

    while(!pq.empty()){
        u=pq.top().first, du=pq.top().second;
//        cout << u << ' ' << du << endl;
        pq.pop();
        if(d[u]!=du) continue;

        for(int i=0;i<adj[u].size();i++){
            v=adj[u][i].first, uv=adj[u][i].second;
            if(d[v]>=du+uv){
                if(d[v]==du+uv) T[v]+=T[u];
                else{
                    d[v]=du+uv;
                    T[v]=T[u];
                    pq.push(pii(v,d[v]));
                }
            }
        }
    }
}

int main(){
//    freopen("QBSCHOOL.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> k >> u >> v >> w;
        adj[u].push_back(pii(v,w));
        if(k==2) adj[v].push_back(pii(u,w));
    }

    IJK();
    cout << d[n] << ' ' << T[n];
}
