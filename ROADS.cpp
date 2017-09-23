#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pp  pair<int, pii>
const int oo=1000000000;
int test, kq, k, n, m, u, v, du, uv, l, t, price1, price2, d[105][10005];
vector <pp> adj[105];

void IJK(){
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            d[i][j]=oo;
    d[1][0]=0;
    pq.push(pp(0,pii(1,0)));

    while(!pq.empty()){
        u=pq.top().second.first, du=pq.top().first, price1=pq.top().second.second;
        pq.pop();

        if(d[u][price1]!=du) continue;
        for(int i=0;i<adj[u].size();i++){
            v=adj[u][i].first, uv=adj[u][i].second.first, price2=adj[u][i].second.second;
            if(d[v][price1+price2]>du+uv && price1+price2<=k){
                d[v][price1+price2]=du+uv;
                pq.push(pp(d[v][price1+price2],pii(v,price1+price2)));
            }
        }
    }
}

int main(){
    freopen("ROADS.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);

    cin >> test;
    while(test--){
        cin >> k >> n >> m;

        for(int i=1;i<=n;i++)
            adj[i].clear();

        for(int i=1;i<=m;i++){
            cin >> u >> v >> l >> t;
            adj[u].push_back(pp(v,pii(l,t)));
        }
        kq=oo;
        IJK();
        for(int i=k;i>=0;i--)
            kq=min(kq,d[n][i]);
        cout << (kq==oo?-1:kq) << endl;
    }
}
