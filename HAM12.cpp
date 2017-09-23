#include <iostream>
using namespace std;
int n, m, k, kq, temp;
const int oo =1e9;
string s;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k >> s;
	s=" "+s;
	for(int i=1;i<m;i++) s+=s[i];
	n+=m-1;
	kq=oo;
	for(int i=1;i<=k;i++){
		string t;
		cin >> t;
		t=" "+t;
		for(int j=1;j<=n-m+1;j++){
			temp=0;
			for(int l=1;l<=m;l++)
				if(t[l]!=s[j+l-1]) temp++;
			kq=min(kq, temp);
		}
	}
	cout << kq;
}
