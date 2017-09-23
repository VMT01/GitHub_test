#include <iostream>
using namespace std;
int m, n, kq, a[1002][1002], f[1002][1002];
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
    for(int i=0;i<=n+1;i++) f[1][i] = 1;
    for(int i=0;i<=m+1;i++) f[i][1] = 1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
			if(a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j-1])
                f[i][j]=min(f[i-1][j], min(f[i][j-1],f[i-1][j-1])) + 1;
            else
                f[i][j]=1;
    kq=1;
    for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
            kq=max(kq,f[i][j]);
    cout << kq;
}
