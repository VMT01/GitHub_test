#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, cnt, cau, khop,
    num[10005], low[10005];
vector <int> C[10005];
bool skhop[10005];

void DFS(int u, int p){
    num[u]=low[u]=++cnt;
    int NumChild=0;
    for(int i=0;i<C[u].size();i++){
        int v=C[u][i];
        if(v!=p){
            if(num[v]!=0) low[u]=min(low[u],num[v]);
            else{
                DFS(v,u);
                low[u]=min(low[u],low[v]);
                NumChild++;
                if(low[v]>num[u]) cau++;
                if(u==p){
                    if(NumChild>=2)
                        skhop[u]=true;
                }
                else{
                    if(low[v]>=num[u])
                        skhop[u]=true;
                }
            }
        }
    }
}

int main(){
//    freopen("GRAPH_.inp","r",stdin);
//    freopen("GRAPH_.out","w",stdout);
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        C[x].push_back(y);
        C[y].push_back(x);
    }
//    for(int i=1;i<=n;i++)
//        C[i].push_back(0);
    for(int i=1;i<=n;i++)
        if(!num[i]) DFS(i,i);
    for(int i=1;i<=n;i++)
        if(skhop[i])
            khop++;
    cout << khop << ' ' << cau;
}
