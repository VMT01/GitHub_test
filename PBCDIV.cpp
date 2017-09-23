#include <iostream>
using namespace std;
int t;
unsigned long long i, j, k, a, b;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(int o=1;o<=t;o++){
		cin >> a >> b;
		i=(b/12)-((a-1)/12);
		j=(b/30)-((a-1)/30);
		k=(b/60)-((a-1)/60);
		cout << (i+j-2*k) << '\n';
	}
}
