#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e18;
typedef pair <int, long long> pil;
int n, m, a, b, x, y, tr[50005];
long long z, kq, d[50005];
vector <pil> C[50005];
queue <int> q;
bool inQ[50005];

void Ford_Bellman(){
    for(int i=1;i<=n;i++) d[i]=oo, inQ[i]=false, tr[i]=0;
    d[a]=0;
    q.push(a);
    inQ[a]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inQ[u]=false;
        for(int i=0;i<C[u].size();i++){
            int v=C[u][i].first;
            long long uv=C[u][i].second;
            if(uv!=0 && d[v]-uv>d[u]){
                d[v]=d[u]+uv;
                tr[v]=u;
                if(!inQ[v]){
                    q.push(v);
                    inQ[v]=true;
                }
            }
        }
    }
}

void upside_down(int u){
    long long t;
    while(u!=a){
        x=tr[u];
        for(int i=0;i<C[x].size();i++)
            if(C[x][i].first==u){
                t=C[x][i].second;
                C[x][i].second=0;
                break;
            }
        for(int i=0;i<C[u].size();i++)
            if(C[u][i].first==x){
                C[u][i].second=-t;
                break;
            }
        u=x;
    }
}

int main(){
//    freopen("HIWAY2.inp","r",stdin);
    cin >> n >> m >> a >> b;
    for(int i=1;i<=m;i++){
        cin >> x >> y >> z;
        C[x].push_back(pil(y,z));
        C[y].push_back(pil(x,z));
    }
    Ford_Bellman();
    if(d[b]==oo){
        cout << -1;
        return 0;
    }
    kq+=d[b];
    upside_down(b);
    Ford_Bellman();
    if(d[b]==oo){
        cout << -1;
        return 0;
    }
    cout << kq+d[b];
}
