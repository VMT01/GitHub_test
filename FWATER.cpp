#include <iostream>
#include <algorithm>
//#include <stdio.h>
using namespace std;
int n, m, cnt, kq,
    h[305];
struct id{
    int x, y, w;
} T[100000];
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
//    freopen("FWATER.inp","r",stdin);
    cin >> n;
    m=1;
    for(int i=1;i<=n;i++){
        T[m].x=0, T[m].y=i;
        cin >> T[m].w;
        m++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            T[m].x=i, T[m].y=j;
            cin >> T[m].w;
            m++;
        }
    m--;
    sort(T+1,T+m+1,cmp);
    for(int i=1;i<=n;i++)
        h[i]=0;
    for(int i=1;i<=m;i++){
        if(findset(T[i].x)!=findset(T[i].y)){
            Union(T[i].x,T[i].y);
            cnt++;
            kq+=T[i].w;
        }
        if(cnt==n){
            cout << kq;
            return 0;
        }
    }
}
