#include <bits/stdc++.h>
using namespace std;
int t, n;
char res[2000005];
int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        int k=0;
        for(int j=1;j<2*n;j++){
            if(j<=n) k+=j;
            else k+=2*n-j;
            res[2*n-j]=k%10+48;
            k/=10;
        }
        for(int j=1;j<2*n;j++) cout << res[j];
        cout << endl;
    }
}
