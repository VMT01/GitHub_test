#include <utility>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> pp;
int n, a, k, kq, h[300005];
pii X[100005], Y[100005], Z[100005];
vector <pp> T;
int findset(int u){
    if(u==h[u]) return u;
    return h[u]=findset(h[u]);
}
//void Union(int u, int v){
//    if((u=findset(u))==(v=findset(v))) return;
//    if(h[u]<h[v]){
//        h[u]+=h[v];
//        h[v]=u;
//    }
//    else{
//        h[v]+=h[u];
//        h[u]=v;
//    }
//}
int main(){
//    freopen("VNEMPIRE.inp","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        X[i]=pii(a,i);
        cin >> a;
        Y[i]=pii(a,i);
        cin >> a;
        Z[i]=pii(a,i);
    }
    sort(X+1,X+n+1);
    sort(Y+1,Y+n+1);
    sort(Z+1,Z+n+1);
//    for(int i=1;i<=n;i++)
//        cout << X[i].first << ' ' << X[i].second << endl;
//    cout << endl;
//    for(int i=1;i<=n;i++)
//        cout << Y[i].first << ' ' << Y[i].second << endl;
//    cout << endl;
//    for(int i=1;i<=n;i++)
//        cout << Z[i].first << ' ' << Z[i].second << endl;
//    cout << endl;
    for(int i=1;i<n;i++){
        T.push_back(pp(abs(X[i].first-X[i+1].first),pii(X[i].second,X[i+1].second)));
        T.push_back(pp(abs(Y[i].first-Y[i+1].first),pii(Y[i].second,Y[i+1].second)));
        T.push_back(pp(abs(Z[i].first-Z[i+1].first),pii(Z[i].second,Z[i+1].second)));
    }
    sort(T.begin(),T.end());
    for(int i=1;i<=n;i++) h[i]=i;
    for(int i=0;i<T.size() && k<n-1;i++){
        int p=findset(T[i].second.first), q=findset(T[i].second.second);
        if(p!=q){
            h[p]=q;
            kq+=T[i].first;
            k++;
        }
    }
    cout << kq;
}
