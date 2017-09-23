#include <iostream>
using namespace std;
int m, n, a[1001], b[1001], f[1001][1001];
int main()
{
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
        cin >> a[i];
    for(int j=1;j<=n;j++)
        cin >> b[j];
    f[0][0]=0;
    for(int i=1;i<=m;i++)
        f[i][1]=(a[i]==b[1])?1:f[i-1][1];
    for(int j=1;j<=n;j++)
        f[1][j]=(a[1]==b[j])?1:f[1][j-1];
    for(int i=2;i<=m;i++)
        for(int j=2;j<=n;j++)
		{
			f[i][j]=max(f[i][j-1],max(f[i-1][j],f[i-1][j-1]));
			if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-2][j-2]+1);
		}
    cout << f[m][n];
}