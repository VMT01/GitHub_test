#include <iostream>
using namespace std;
int n, s[15], sz;
string st, k;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> st;
		sz=max((int)st.size(),sz);
		for(int j=0;j<st.size();j++)
			s[j]^=(int)st[j];
	}
	for(int i=0;i<sz;i++)
		if(s[i]!=0) k+=(char)s[i];
	if(k=="") cout << -1;
	else cout << k;
}
