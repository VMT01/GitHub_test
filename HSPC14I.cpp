#include <iostream>
#include <algorithm>
using namespace std;
int a[3];
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> a[0] >> a[1] >> a[2]){
		sort(a,a+3);
		cout << max(a[1]-a[0],a[2]-a[1])-1 << '\n';
	}
}
