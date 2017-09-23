#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1000001], f[1000001];
int solve(int x){
    int i=0, j=x;
    while(j!=0){		
    	i++;;
        a[i]=j%10;
        j/=10;
 	}
    sort(a+1,a+i+1);
    x=0;
    for(int j=1;j<=i;j++)
 	    x=x*10+a[j];
    return x;
}
int main(){
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    f[1]=1;
    for(int i=2;i<=50;i++)
		f[i]=solve(f[i-1]*2);
    if(n<=25){
		cout << f[n]; 
		return 0;
	}
    cout << f[25+(n-25)%6];
}

