#include <bits/stdc++.h>
using namespace std;
int t, n, k;
unsigned long long F[26][26];
int main(){
    F[0][0]=1;
    for(int i=1;i<=25;i++)
        for(int j=1;j<=i;j++)
            F[i][j]=F[i-1][j-1]+F[i-1][j]*j;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> k;
        cout << F[n][k] << endl;
    }
}
