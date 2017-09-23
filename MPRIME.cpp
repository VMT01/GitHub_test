#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int k;
bool Ngto(unsigned long long i){
	for(unsigned long long j=2;j<=sqrt(i);j++)
		if(i%j==0) return false;
    return true;
}
void Solve(){
	string Sr, Sl;
    int res=0, count=0;
    unsigned long long i=2, j;
    while(res<k){
 		if(Ngto(i)){
	        count++;
	        stringstream ss1;
	        ss1 << i;
	        Sr=ss1.str();
            if(count%2==0){
 	            stringstream ss2(Sl+Sr);
 	            ss2 >> j;
                if(Ngto(j)) res++;
                count=0;
        	}
            else Sl=Sr;
    	}
        i++;
	}
    cout << j;
}
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
    Solve();
}
