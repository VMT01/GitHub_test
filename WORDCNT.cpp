#include <iostream>
#include <sstream>
using namespace std;
string s, a;
int t, d1, d2, d3, d4;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	getline(cin,s);
	while(t--)
	{
		getline(cin,a);
		d1=d3=d4=0;
		stringstream ss(a);
		while(ss>>s)
		{
			d2=s.size();
			if(d2==d3)
				d4++;
			else
			{
				d1=max(d1,d4);
				d4=1, d3=d2;
			}
		}
		d1=max(d1,d4);
		cout << d1 << '\n';
	}
}