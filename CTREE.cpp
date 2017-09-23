#include <iostream>
#include <vector>
using namespace std;
typedef vector <int> dl;
dl adj[10001];
int n, u, v, kq=999999999, nho,
    cx[10001], F[10001][4], s[4]={0,2,3,1}, cr[10001];
void DFS(int u)
{
    cx[u]=1;
    for(int i=0;i<adj[u].size();i++)
        if(cx[adj[u][i]]==0)
        {
            DFS(adj[u][i]);
            cx[adj[u][i]]=1;
            for(int j=1;j<=3;j++)
                F[u][j]+=min(F[adj[u][i]][s[j]],F[adj[u][i]][s[s[j]]]);
        }
    F[u][1]++;
    F[u][2]+=2;
    F[u][3]+=3;
}
void trace(int u)
{
    cx[u]=1;
    for(int i=0;i<adj[u].size();i++)
        if(cx[adj[u][i]]==0)
        {
            if(F[adj[u][i]][s[cr[u]]]<F[adj[u][i]][s[s[cr[u]]]])
                cr[adj[u][i]]=s[cr[u]];
            else
                cr[adj[u][i]]=s[s[cr[u]]];
            trace(adj[u][i]);
        }
}
int main()
{
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for(int i=1;i<=3;i++)
        if(kq>F[1][i])
        {
            kq=F[1][i];
            nho=i;
        }
    for(int i=1;i<=n;i++)
        cx[i]=0;
    cr[1]=nho;
    trace(1);
    cout << kq;
    for(int i=1;i<=n;i++)
        cout << '\n' << cr[i];
}
