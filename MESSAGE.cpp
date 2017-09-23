#include <bits/stdc++.h>
#define maxn 1000001
#define x first
#define y second
using namespace std;
typedef pair < int , int > II;
II e[maxn];
vector < int > g[maxn];
 int n,m,deg[maxn],cl[maxn],low[maxn],num[maxn],s[maxn],sn=0,id=0,d[maxn],slt=0,lt[maxn];
void doc()
{
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
 int u,v;
 cin>>u>>v;
 e[i]=II(u,v);
 deg[u]++;
 g[u].push_back(v);
 }
}

void dfs(int u)
{
 cl[u]=1;
 s[++sn]=u;
 low[u]=num[u]=++id;
 for(int i=0;i<deg[u];i++)
 {
 int v=g[u][i];
 if(cl[v]==0)
 {
 dfs(v);
 low[u]=min(low[u],low[v]);
 }else if(cl[v]==1)low[u]=min(low[u],num[v]);
}

 if(low[u]==num[u])
 {
 slt++;
 int v;
 do
 {
 v=s[sn--];
 lt[v]=slt;
 cl[v]=2;
 }while(v!=u);
 }
}
void tinh()
{
 for(int i=1;i<=n;i++) if(cl[i]==0) dfs(i);
 for(int i=1;i<=m;i++)
 {
 int u=e[i].x,v=e[i].y;
 if(lt[u]!=lt[v]) d[lt[v]]=1;
 }
 int dem=0;
 for(int i=1;i<=slt;i++) if(d[i]==0) dem++;
 cout<<dem;
}

int main()
{
 ios::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 doc();
 tinh();
}
