#include <iostream>
#include <algorithm>
using namespace std;
int m, n, h[10005], cnt, kq;
struct id{
    int x, y, w;
} T[15005];
int findset(int u){
    while(h[u]!=0) u=findset(h[u]);
    return u;
}
void Union(int u, int v){
    if((u=findset(u))==(v=findset(v))) return;
    if(h[u]<h[v]){
        h[u]+=h[v];
        h[v]=u;
    }
    else{
        h[v]+=h[u];
        h[u]=v;
    }
}
bool cmp(id u,id v){
    return u.w<v.w;
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++)
        cin >> T[i].x >> T[i].y >> T[i].w;
    sort(T+1,T+m+1,cmp);
    for(int i=1;i<=n;i++)
        h[i]=0;
    for(int i=1;i<=m;i++){
        if(findset(T[i].x)!=findset(T[i].y)){
            Union(T[i].x,T[i].y);
            cnt++;
            kq+=T[i].w;
        }
        if(cnt==n-1){
            cout << kq;
            return 0;
        }
    }
}
