#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
vector <string> a;
string s, kq;
bool cmp(string s1, string s2)
{
    if(s1.length()==s2.length())
    {
        if(s1.compare(s2)==-1) return true;
        return false;
    }
    if(s1.length()<s2.length())
    {
        for (int i=0;i<s1.length();i++)
        {
            if(s1[i]<s2[i]) return true;
            if(s1[i]>s2[i]) return false;
        }
        for (int i=s1.length();i<s2.length();i++)
        {
            if(s1[0]<s2[i]) return true;
            if(s1[0]>s2[i]) return false;
        }
        return false;
    }
    if(s1.length()>s2.length())
    {
        for (int i=0;i<s2.length();i++)
        {
            if(s1[i]<s2[i]) return true;
            if(s1[i]>s2[i]) return false;
        }
        for (int i=s2.length();i<s1.length();i++)
        {
            if(s1[i]<s2[0]) return true;
            if(s1[i]>s2[0]) return false;
        }
        return false;
    }
}
int main()
{
    while(cin>>s!=NULL)
        a.push_back(s);
    sort(a.begin(),a.end(),cmp);
    for(int i=a.size()-1;i>=0;i--)
        kq+=a[i];
    for(int i=0;i<kq.size();i++)
        printf("%c",kq[i]);
}
