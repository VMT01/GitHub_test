
#include <bits/stdc++.h>
using namespace std;
const long long base=20122007;
long long n, res=1;

long long cal(long long u){
    if(u==1) return 3;
    long long ter=cal(u/2)%base;
    if(u%2==0) return (ter*ter)%base;
    return ((ter*ter%base)*3)%base;
}

long long cal1(long long u){
    return (cal(u)-1+base)%base;
}

int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(long long i=1;i*i<=n;i++)
        if(n%i==0){
            if(i*i==n) res=res*cal1(i)%base;
            else res=((res*cal1(i)%base) * cal1(n/i)) % base;
        }
    cout << res;
}
