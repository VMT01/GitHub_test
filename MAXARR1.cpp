#include <iostream>
using namespace std;
int n[100001], a[100001], f[100001], m, t;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i];
		m=max(m,n[i]);
	}
	a[0]=0, a[1]=1;
	for(int i=1;i<=m/2;i++){
		a[2*i]=a[i];
		a[2*i+1]=a[i]+a[i+1];
	}
	f[1]=1;
	for(int i=2;i<=m;i++)
		f[i]=max(f[i-1],a[i]);
	for(int i=1;i<=t;i++)
		cout << f[n[i]] << '\n';
}
