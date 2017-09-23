#include <bits/stdc++.h>
using namespace std;
string s1, s2, s;
int kq[405];
int m, n;

void solve(int i, int a, int b){
    if(i>m+n){
        for(int i=1;i<=m+n;i++) cout << kq[i];
        exit(0);
    }
    if(s[i]==s1[a]){
        kq[i]=1;
        solve(i+1,a+1,b);
    }
    if(s[i]==s2[b]){
        kq[i]=2;
        solve(i+1,a,b+1);
    }
}

int main(){
//    freopen("NKH.inp","r",stdin);
    cin >> s1 >> s2 >> s;
    m=s1.size(), n=s2.size();
    s1=' '+s1, s2=' '+s2, s=' '+s;
    solve(1,1,1);
}
