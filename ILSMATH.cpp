#include <bits/stdc++.h>
using namespace std;
int n, i;
double x;

int main(){
    cin >> n;
    if(n==1){
        cout << 3 << endl << 1 << endl << 2 << endl << 3;
        return 0;
    }
    if(n==2){
        cout << 1 << endl << 4;
        return 0;
    }
    if(n==3){
        cout << 2 << endl << 5 << endl << 6;
        return 0;
    }
    if(n==4){
        cout << 1 << endl << 7;
        return 0;
    }
    if(n==5){
        cout << 1 << endl << 8;
        return 0;
    }
    i=2;
    while(1){
        x+=log10(i);
        if((int)x+1==n){
            cout << 1 << endl << i;
            return 0;
        }
        if((int)x+1>n){
            cout << "NO";
            return 0;
        }
        i++;
    }
}
