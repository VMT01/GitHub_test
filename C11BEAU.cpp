#include <iostream>
using namespace std;
int t;
unsigned long long countA, countB, maxA, maxB;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> countA >> countB >> maxA >> maxB;
		if(maxA==0) countA=0;
		if(maxB==0) countB=0;
		if(countA > countB){
			swap(countA, countB);
			swap(maxA, maxB);
		}
		cout << min(countB, maxB*(countA+1))+countA << '\n';
	}
}
