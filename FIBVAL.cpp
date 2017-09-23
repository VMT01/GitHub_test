#include <bits/stdc++.h>
using namespace std;
int t, u, v, k,
    F[] = {1, 2, 3, 5, 1, 6, 0, 6, 6, 5, 4, 2, 6, 1, 0, 1};
bool ktra;
int main(){
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        ktra=false;
        cin >> u >> v;
        u--, v--;
        k=(v-u+1)/16;
        if(k>=2) cout << k*16 << endl;
        else{
            for(int i=u+1;i<=min(u+20,v);i++)
                if(F[i%16]==F[(i+15)%16]) {ktra=true;break;}
            if(ktra==true) cout << 2 << endl;
            else cout << -1 << endl;
        }

    }
}
