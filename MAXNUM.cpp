#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> pinp;
int n, p, kq=1e9;
vector <pinp> ngtop;
vector <int> ngto;
bool Era[30005];

void sang(){
    Era[0]=Era[1]=true;
    for(int i=4;i<=30000;i+=2) Era[i]=true;
    for(int i=3;i<=30000;i+=2)
        if(Era[i]==false)
            for(int j=2*i;j<=30000;j+=i) Era[j]=true;
    for(int i=1;i<=30000;i++)
        if(Era[i]==false) ngto.push_back(i);
}

void solve(int a){
    for(int i=0;i<ngtop.size();i++){
        if(a==1) return;
        if(a%ngtop[i].first.first==0)
            while(a%ngtop[i].first.first==0){
                a/=ngtop[i].first.first;
                ngtop[i].second++;
            }
    }
}

int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> p;
    sang();
    for(int i=0;i<ngto.size();i++)
        if(ngto[i]<=p && p%ngto[i]==0){
            int dem=0;
            while(p%ngto[i]==0){
                p/=ngto[i];
                dem++;
            }
            ngtop.push_back(pinp(pii(ngto[i],dem),0));
        }
    for(int i=2;i<=n;i++) solve(i);
    for(int i=0;i<ngtop.size();i++) kq=min(kq,ngtop[i].second/ngtop[i].first.second);
    cout << kq;
}
