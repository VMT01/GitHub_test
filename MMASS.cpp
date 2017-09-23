#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
string s;
stack <int> S;
int M(char x)
{
    if(x=='H') return 1;
    if(x=='C') return 12;
    if(x=='O') return 16;
}
int main()
{
    cin >> s;
    s='('+s+')';
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i])) S.push(M(s[i]));
        if(s[i]=='(') S.push(0);
        if(isdigit(s[i])) S.top()*=s[i]-'0';
        if(s[i]==')')
        {
            int p=0;
            while(S.top()!=0)
            {
                p+=S.top();
                S.pop();
            }
            S.pop();
            S.push(p);
        }
    }
    printf("%d",S.top());
}
