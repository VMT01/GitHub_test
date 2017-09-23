#include <bits/stdc++.h>
using namespace std;
const int oo=1e9;
int n, m, a, b, kq1,
    C[105][105], d[105], tr[105];
bool inQ[105];
stack <int> kq;
void Ford_Bellman(){
    queue <int> q;
    for(int i=1;i<=n;i++) d[i]=oo, inQ[i]=false, tr[i]=0;
    d[a]=0;
    q.push(a), inQ[a]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop(), inQ[u]=false;
        for(int i=1;i<=n;i++)
        if(C[u][i]!=0 && d[i]>d[u]+C[u][i]){
            d[i]=d[u]+C[u][i], tr[i]=u;
            if(!inQ[i]) q.push(i), inQ[i]=true;
        }
    }
    int i=b;
    while(tr[i]!=0){
        C[i][tr[i]]=-C[i][tr[i]];
        C[tr[i]][i]=0;
        i=tr[i];
    }
}
void solve(){
    Ford_Bellman();
    kq1+=d[b];
    if(kq1==oo){cout << -1;return;}
    Ford_Bellman();
    kq1+=d[b];
}
void printkq(){
    cout << endl << kq.size()+1 << ' ';
    while(!kq.empty()){
        cout << kq.top() << ' ';
        kq.pop();
    }
    cout << b;
}
void trace(int u){
    for(int i=1;i<=n;i++){
        if(C[u][i]<0){
            kq.push(i);
            if(i==a) printkq();
            trace(i);
        }
    }
}
int main(){
//    freopen("HIWAY.inp","r",stdin);
    cin >> n >> m >> a >> b;
    for(int i=1;i<=m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        C[x][y]=C[y][x]=z;
    }
    solve();
    cout << kq1;
    trace(b);
}
