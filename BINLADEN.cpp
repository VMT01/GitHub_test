#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int oo=3000000;
int n, m, t, d, kq=oo, D[22225];
vector <pii> C[22225];
//bool cx[2500][15];

void IJK(pii a){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0;i<=d;i++){
        D[i]=oo;
//        for(int j=0;j<=d;j++) cx[i][j]=false;
    }
    D[a.first]=a.second;
    pq.push(pii(a.second,a.first));

    int u, v, du, uv;
    while(!pq.empty()){
        u=pq.top().second, du=pq.top().first;
        pq.pop();
        if(D[u]!=du) continue;

        for(int i=0;i<C[u].size();i++){
            v=C[u][i].first, uv=C[u][i].second;
            if(D[v]>du+uv){
                D[v]=du+uv;
                pq.push(pii(D[v],v));
            }
        }
    }
}

int main(){
//    freopen("BINLADEN.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);

    cin >> m >> n;
//    for(int i=0;i<=m;i++)
//        for(int j=0;j<=n;j++)
//            C[i][j]=oo;

    for(int i=1;i<=n;i++){
        cin >> t;
        C[0].push_back(pii(++d,t));
        C[d].push_back(pii(0,t));
    }
    ++d;
    for(int i=1;i<2*m;i++){
        if(i%2==1){
            d=d-n+1;
            for(int j=1;j<n;j++){
                cin >> t;
                C[d-1].push_back(pii(d,t));
                C[d].push_back(pii(d-1,t));
                ++d;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                cin >> t;
                C[d-n].push_back(pii(d,t));
                C[d].push_back(pii(d-n,t));
                ++d;
            }
        }
    }

    d--;

//    for(int i=0;i<=d;i++)
//        for(int j=0;j<C[i].size();j++)
//            cout << i << ' ' << C[i][j].first << ' ' << C[i][j].second << endl;
//    cout << endl;

    for(int i=0;i<C[0].size();i++){
        IJK(C[0][i]);
        kq=min(kq,D[d]);
    }
    cout << kq;
}
