include <iostream>
#include <sstream>
using namespace std;
string s, a;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a;
	for(int i=1;i<=100000;i++){
		stringstream ss;
		ss << i;
		s+=ss.str();
	}
	cout << s.find(a)+1;
}
