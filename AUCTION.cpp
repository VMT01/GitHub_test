#include <iostream>
using namespace std;
int n, m, a[1001], ans, kq, gtri;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1;i<=m;i++){
		ans=0;
		for(int j=1;j<=m;j++)
			ans+=(a[j]>=a[i])*a[i];
		ans = min(ans, n*a[i]);
		if(ans>=kq){
			kq=ans;
			gtri=a[i];
		}
	}
	cout << gtri << ' ' << kq;
}
