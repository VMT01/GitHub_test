#include <bits/stdc++.h>
using namespace std;
long long n, b, tu, mau, kq;
int main(){
    cin >> b >> n;
    mau=n*n;
    for(long long i=1;i<2*n;i++){
        tu=i*b*(2*n-i);
        if(tu%mau==0) kq++;
    }
    cout << kq;
}
