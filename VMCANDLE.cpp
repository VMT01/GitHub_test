#include <bits/stdc++.h>
using namespace std;
int64_t k, l, r, mid;
int main(){
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);
    cin >> k;
    l=1, r=2*k;
    while(l<=r){
        mid=(l+r)/2;
        if((mid-(int64_t)sqrt(mid))<k) l=mid+1;
        else{
            if(((mid-(int64_t)sqrt(mid))==k) && ((int64_t)sqrt(mid)-sqrt(mid)!=0)) {cout << mid;return 0;}
            else r=mid-1;
        }
    }
}
