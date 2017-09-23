#include <iostream>
using namespace std;
const int nmax = 100001;
int ke[nmax][2], cnt[nmax], n, c, dem=1, e, b1, b2;
void DFS (int x)
{
	cnt[x-1]=dem;
	dem++;
	if(ke[x-1][0]!=0)
  {
    DFS(ke[x-1][0]);
		dem--;
	}
	if(ke[x-1][1]!=0)
	{
		DFS(ke[x-1][1]);
		dem--;
	}
}
int main()
{
  ios_base::sync_with_stdio("false");
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> c;
  for(int i=1;i<=c;i++)
	{
	  cin >> e >> b1 >> b2;
		ke[e-1][0]=b1;
		ke[e-1][1]=b2;
	}
	DFS(1);
	for(int i=0;i<n;i++)
    cout << cnt[i] << '\n';
}
