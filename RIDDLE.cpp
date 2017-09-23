#include <bits/stdc++.h>
using namespace std;
int t, n, k, kq,
    a[100005], b[100005];

bool ktra(int i){
    for(int j=1;j<=i;j++) b[j]=a[j];
    sort(b+1,b+i+1);
    int sum=0;
    for(int j=1;j<=i;j++){
        if(b[j]>sum+1) return false;
        sum+=b[j];
        if(sum>=k) return true;
    }
    return false;
}

void solve(){
    kq=-1;
    int l=1, r=n, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(ktra(mid)){
            kq=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
}

int main(){
//    freopen("RIDDLE.inp","r",stdin);
//    freopen("RIDDLE.out","w",stdout);
    cin >> t;
    for(int j=1;j<=t;j++){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        solve();
        cout << kq << endl;
    }
}
