#include <bits/stdc++.h>
using namespace std;
const int oo=-1000000000;

int n, p, kq,
    C[205], F[205][205], tr[205][205];
bool way[205][205];

void DFS(int u){
    F[u][1]=C[u];
    for(int v=1;v<=n;v++)
        if(way[u][v]==true){
            way[v][u]=false;
            DFS(v);
            for(int i=p;i>=1;i--)
                for(int j=1;j<i;j++)
                    if(F[u][i]<F[u][j]+F[v][i-j]){
                        F[u][i]=F[u][j]+F[v][i-j];
                        tr[v][i]=i-j;
                    }
        }
}

void trace(int u, int p){
    for(int v=n;v>=1;v--)
        if(way[u][v]==true && tr[v][p]>0){
            trace(v,tr[v][p]);
            p-=tr[v][p];
        }
    cout << u << ' ';
}

int main(){
//    freopen("PTREE.inp","r",stdin);
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> p;
    for(int i=1;i<=n;i++) cin >> C[i];
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        way[u][v]=way[v][u]=true;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
            F[i][j]=oo;
    DFS(1);

    int st=1;
    for(int i=2;i<=n;i++)
        if(F[i][p]>F[st][p]) st=i;
    trace(st,p);
}
