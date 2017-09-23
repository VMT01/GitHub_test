#include <iostream>
using namespace std;
const int nmax=1e6+1;
int n, kq,
    h[nmax], l[nmax], r[nmax+1];
void enter(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> h[i];
}

void solve(){
    l[0]=r[n+1]=0;
    int a=1;
    for(int i=1;i<=n;i++){
        while(h[i]<=h[a])
            a--;
        l[i]=a;
        a=i+1;
    }
    a=n;
    for(int i=n;i>=1;i--){
        while(h[i]<=h[a])
            a++;
        r[i]=a;
        a=i-1;
    }
    for(int i=1;i<=n;i++)
        if(h[i]<=r[i]-l[i]-1)
            kq=max(kq,h[i]);
    cout << kq;
}

int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    enter();
    solve();
}
