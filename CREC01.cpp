#include <iostream>
using namespace std;
int m, n;
unsigned long long kq, h[1001], cal[1001], l[1001];
string a;
int main(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> a;
        a='#'+a;
        for(int j=1;j<=n;j++){
            h[j]=(a[j]=='1'?h[j]+1:0);
            l[j]=j;
            while(h[l[j]-1]>=h[j] && h[j]>0) l[j]=l[l[j]-1];
            if(a[j]=='1'){
                cal[j]=cal[l[j]-1]+h[j]*(j-l[j]+1);
                kq+=cal[j];
            }
            else cal[j]=0;
        }
    }
    cout << kq;
}
