#include <iostream>
using namespace std;
int k, h;
string s;
int main(){
	ios_base::sync_with_stdio("false");
	cout.tie(NULL);
	cin >> k >> h;
	while(k!=0){
		s=char(k%2+48)+s;
		k/=2;
	}
	cout << s;
}
