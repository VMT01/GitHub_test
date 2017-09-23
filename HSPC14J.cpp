#include <iostream>
using namespace std;
int n, k;
bool era[1005];
void makeset(){
	era[1]=true;
	for(int i=2;i<=1000;i++)
		era[i]=false;
}
void SANG(int n,int k){
	for(int i=2;i<=n;i++)
			if(!era[i])
				for(int j=1;j<=n/i;j++)
					if(!era[i*j]){
						k--;
						if(k==0){
							cout << i*j << '\n';
							return;
						}
						era[i*j]=true;
					}
}
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> n >> k){
		makeset();
		SANG(n, k);
	}
}
