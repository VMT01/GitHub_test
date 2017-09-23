#include <bits/stdc++.h>
using namespace std;
typedef vector<int> bigNum;
const int baseDigit = 3;
const int base = 1000;

void str2big(string s, bigNum & a){
    while (s.size()%baseDigit) s = '0' + s;
    for (int i=s.size()-1; i>=0; i-=baseDigit){
            int x = 0;
            for (int j = i-baseDigit+1;j<=i;j++)
                x = x*10 + s[j]-48;
            a.push_back(x);
        }
}

bool operator > (bigNum a, bigNum b){
    if (a.size()!=b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i>=0; i--)
        if (a[i]!=b[i])
            return a[i]>b[i];
    return false; // a = b
}

bigNum operator + (bigNum a, bigNum b){
    for (int i = 0, carry = 0; i<max(a.size(),b.size()) || carry;i++){
            if (i==a.size())
                a.push_back(0);
            a[i] += carry + (i<b.size()?b[i]:0);
            carry = a[i] >= base;
            if (carry)
                a[i]-=base;
    }
   return a;
}

void display(bigNum a){
    cout<<(a.empty()?0:a.back());
    for (int i =a.size()-2; i>=0; i--)
        cout <<setw(baseDigit)<<setfill('0')<<a[i];
}

bool operator < (bigNum a, bigNum b){
    return b>a;
}

bigNum operator - (bigNum a, bigNum b){
    for (int i=0, carry = 0; i<a.size() || carry; i++){
        a[i] = a[i] - carry - (i<b.size()?b[i]:0);
        carry = a[i]<0;
        if (carry)
            a[i] += base;
    }
    while (a.size()>1 && !a.back())
        a.pop_back();
    return a;
}

bigNum operator * (bigNum a, int k){
    for (int i = 0, carry = 0; i < a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back(0);
        long long t = (long long) k * a[i] + carry;
        carry = (int) (t / base);
        a[i] = (int) (t % base);
    }
    return a;
}

bigNum operator * (bigNum a, bigNum b){
    bigNum t,c;
    int nc = a.size() + b.size();
    for (int i = 0; i<nc; i++)
        c.push_back(0);
    for (int i = 0; i<b.size(); i++){
        t = a*b[i];
        for (int j = 0;j<i; j++)
            t.insert(t.begin(),0);
        c = c + t;
    }
    while (c.size()>1 && !c.back()) c.pop_back();
    return c;
}

bigNum a, b;

int main(){
//    freopen("BIGNUM.INP","r",stdin);
//    freopen("BIGNUM.OUT","w",stdout);
    string sa,sb;
    cin>>sa>>sb;    // Nhap vao 2 so lon
    str2big(sa,a);
    str2big(sb,b);

    display(a+b); // Hien thi a + b
	cout << endl;
    bigNum c = (a>b?a-b:b-a);   //Tinh a-b
    if (a<b) cout<<"-";
    display(c);
	cout << endl;
    display(a*b);   // Hien thi a * b
}
