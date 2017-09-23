include <iostream>
using namespace std;
int c, n, kq, W[17], a[17];
void solve(){
	int nho=0;
	for(int i=1;i<=n;i++)
		nho+=W[i]*a[i];
	if(nho<=c) kq=max(kq,nho);
}
void Try(int i){
	a[i]=0;
	if(i==n) solve();
	else Try(i+1);
	a[i]=1;
	if(i==n) solve();
	else Try(i+1);
}
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> c >> n;
	for(int i=1;i<=n;i++)
		cin >> W[i];
	Try(1);
	cout << kq;
}
