#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, cnt, kq,
    num[10005], low[10005];
vector <int> C[10005];
stack <int> S;

void DFS(int u){
    num[u]=low[u]=cnt++;
    S.push(u);
    for(int i=0;i<C[u].size();i++){
        int v=C[u][i];
        if(num[v]) low[u]=min(low[u],num[v]);
        else{
            DFS(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==num[u]){
        kq++;
        int v;
        do{
            v=S.top();
            num[v]=low[v]=n+1;
            S.pop();
        }
        while(u!=v);
    }
}

int main(){
//    freopen("TJALG.inp","r",stdin);
//    ios_base::sync_with_stdio("false");
//    cin.tie(NULL);
//    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        C[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(!num[i])
            DFS(i);
    cout << kq;
}
