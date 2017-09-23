#include <iostream>
using namespace std;
string s;
int n;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> s && s!="[END]"){
		cin >> n;
		n=(n%5==0)?5:n%5;
		cout << ((n==2||n==5)?"Hanako\n" : "Taro\n");
	}
}
