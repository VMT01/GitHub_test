#include <bits/stdc++.h>
using namespace std;
string s;
char x, y;
unsigned long long dem, kq;
int main(){
//    freopen("VMRR.inp","r",stdin);
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin,s);
    cin >> x;
    cin >> y;
    for(int i=0;i<s.size();i++){
        if(s[i]==y) kq+=dem;
        if(s[i]==x) dem++;
    }
    cout << kq;
}
