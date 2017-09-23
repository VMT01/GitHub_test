#include <iostream>
#include <vector>
//#include <algorithm>
//#include <stdio.h>
using namespace std;
const int oo = 1e9;
int m, n, k, T[105][105], trace[105][105];
vector <int> kq;
void backtr(int u, int v){
    if(u==0||v==0) return;
    backtr(u,trace[u][v]);
    if(trace[u][v]!=0) kq.push_back(trace[u][v]);
    backtr(trace[u][v],v);
}
int main(){
//    freopen("FLOYD.inp","r",stdin);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        T[x][y]=T[y][x]=w;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(T[i][j]==0) T[i][j]=oo;
    for(int t=1;t<=n;t++)
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(T[i][j]>T[i][t]+T[t][j]){
                    trace[i][j]=trace[j][i]=t;
                    T[i][j]=T[j][i]=T[i][t]+T[t][j];
                }
    for(int i=1;i<=k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0) cout << (T[b][c]==oo?0:T[b][c]) << endl;
        else{
            if(b==c) cout << 1 << ' ' << b << endl;
            else{
                backtr(b,c);
                cout << kq.size()+2 << ' ' << b;
                for(int j=0;j<kq.size();j++)
                    cout << ' ' << kq[j];
                cout << ' ' << c << endl;
                kq.clear();
            }
        }
    }
}
