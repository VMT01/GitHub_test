#include <iostream>
#include <cmath>
using namespace std;
int n, d;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> n){
		d=0;
		for(int i=2;i<=sqrt(2*n);i++){
			if(2*n%i==0)
				if((i+(2*n/i)-1)%2==0)
					d++;
		}
		cout << d << '\n';
	}
}
