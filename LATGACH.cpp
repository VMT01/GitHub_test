#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector <int> bigNum;
const int base =10;
const int baseDigit =1;
int n, t;
bigNum a, b, c;
bigNum operator + (bigNum a, bigNum b)
{
    for(int i=0,carry=0;i<max(a.size(),b.size())||carry;i++)
    {
        if(i==a.size())
            a.push_back(0);
        a[i]+=carry+(i<b.size()?b[i]:0);
        carry = a[i] >= base;
        if(carry)
            a[i]-=base;
    }
    return a;
}
void display(bigNum a)
{
    cout << (a.empty()?0:a.back());
    for(int i=a.size()-2;i>=0;i--)
        cout << setw(baseDigit) << setfill('0') << a[i];
    cout << endl;
}
int main()
{
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        a.clear();
        b.clear();
        c.clear();
        cin >> n;
        a.push_back(1);
        b.push_back(2);
        if(n==1)
        {
            display(a);
            continue;
        }
        if(n==2)
        {
            display(b);
            continue;
        }
        while(n>2)
        {
            c=a+b;
            a=b;
            b=c;
            n--;
        }
        display(c);
    }
}
