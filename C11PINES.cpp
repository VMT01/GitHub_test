#include <iostream>
using namespace std;
int N;
long long  D, mini, A[10001], kq;
bool dk;
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cin >> N >> D;
	mini=1e9;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		mini=min(mini,A[i]);
	}
	dk=true;
	for(int i=1;i<=N;i++){
		A[i]-=mini;
		if(A[i]%D!=0) dk=false;
		kq+=A[i];
	}	
	if(!dk){
		cout << -1;
		return 0;
	}
	kq/=D;
	cout << kq;
}
