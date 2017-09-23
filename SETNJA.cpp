#include <bits/stdc++.h>
using namespace std;
typedef vector <int> bigNum;
const int base =1000000000;
const int baseDigit =9;

/* bigNum */
bigNum operator + (bigNum a, bigNum b){
    for(int i=0,carry=0;i<min(a.size(),b.size())||carry;i++){
        if(i==a.size()) a.push_back(0);
        a[i]+=carry + (i<b.size()?b[i]:0);
        carry = a[i]>=base;
        if(carry) a[i]-=base;
    }
    return a;
}
bigNum operator * (bigNum a,int k){
    for(int i=0,carry=0;i<a.size()||carry;++i){
        if(i==a.size()) a.push_back(0);
        long long t=(long long)k*a[i]+carry;
        carry=(int)(t/base);
        a[i]=(int)(t%base);
    }
    return a;
}
void display(bigNum a){
    cout << (a.empty()?0:a.back());
    for(int i=a.size()-2;i>=0;i--)
        cout << setw(baseDigit) << setfill('0') << a[i];
}
/* bigNum */

bigNum F[10005], C[10005];
string s;

int main(){
    ios_base::sync_with_stdio("False");cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    s='$'+s;
    F[0].push_back(1), C[0].push_back(1);
    for(int i=1;i<s.size();i++)
        if(s[i]=='*') C[i]=C[i-1]*3;
        else C[i]=C[i-1];
    for(int i=1;i<s.size();i++){
        if(s[i]=='L') F[i]=F[i-1]*2;
        if(s[i]=='P') F[i]=F[i-1];
        if(s[i]=='R') F[i]=F[i-1]*2+C[i];
        if(s[i]=='*') F[i]=F[i-1]*5+C[i-1];
    }
    display(F[s.size()-1]);
}
