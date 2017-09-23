#include <bits/stdc++.h>
using namespace std;
bool Era[2700005];
vector <unsigned long long> ngto;
int t, k;
unsigned long long n;

void Eratho(){
    Era[0]=Era[1]=true;
    Era[2]=false;
    for(int i=4;i<=2700000;i+=2)
        Era[i]=true;
    for(int i=3;i<=2700000;i+=2)
        if(Era[i]==false)
            for(int j=2*i;j<=2700000;j+=i) Era[j]=true;
    for(unsigned long long i=1;i<=2700000;i++)
        if(Era[i]==false) ngto.push_back(i);
}

void solve(unsigned long long n, int k){
    bool ok=true;
    unsigned long long kq=1;
    for(int i=0;i<k;i++){
        if(kq>n/ngto[i]){
            ok=false;
            break;
        }
        kq*=ngto[i];
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    int i=0;
    while(kq/ngto[i]<=n/ngto[i+k]){
        kq=kq/ngto[i]*ngto[i+k];
        i++;
    }
    cout << kq << endl;
}

int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    Eratho();
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> k;
        solve(n, k);
    }
}
