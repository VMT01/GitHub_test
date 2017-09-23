#include <iostream>
using namespace std;
int n, m, k;
long long x, x1, x2,
		c[101], a[101][501], f[101][501];
long long X(long long a){
	return a*(a+1)/2;
}
long long solve(int i, int j){
	j++;	
	x1=c[i]/j, x2=x1+1;
	return (c[i]%j)*X(x2)+(j-c[i]%j)*X(x1);	
}
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cin >> n >> m >> k;
	if(n<k){
		cout << n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> x;
		c[x]++;
	}
	for(int i=1;i<=m;i++){
		a[i][0]=X(c[i]);
		for(int j=1;j<=k;j++)
			a[i][j]=solve(i,j);
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<=k;j++)
			for(int t=0;t<=j;t++)
				if(f[i][j]!=0)
					f[i][j]=min(f[i][j],f[i-1][j-t]+a[i][t]);
				else
					f[i][j]=f[i-1][j-t]+a[i][t];
	cout << f[m][k];
} 
