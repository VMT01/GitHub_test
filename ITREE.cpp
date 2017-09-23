#include <bits/stdc++.h>
using namespace std;
const int oo=1000000000;

int t, n, u, c;
double F[1005], C[1005][1005];
//bool way[1005][1005];
vector <int> dsk[1005];

void DFS(int u){
//    for(int v=1;v<=n;v++)
//        if(way[u][v]==true){
//            way[v][u]=false;
//            DFS(v);
//            F[u]+=min(F[v],C[u][v]);
//        }
    if(dsk[u].size()==0) F[u]=oo;
    else{
        for(int i=0;i<dsk[u].size();i++){
            int v=dsk[u][i];
            DFS(v);
            F[u]+=min(F[v],C[u][v]);
        }
    }
}

int main(){
//    freopen("ITREE.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){

        for(int i=1;i<=n;i++) dsk[i].clear(), F[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)   C[i][j]=0;

        cin >> n;
        for(int i=2;i<=n;i++){
            cin >> u >> c;
            dsk[u].push_back(i);
            C[u][i]=C[i][u]=c;
        }
        DFS(1);
        cout << setprecision(2) << fixed << F[1] << endl;
    }
}
