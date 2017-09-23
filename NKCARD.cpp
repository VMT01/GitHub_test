#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;
int m, k;
char s;
list <int> l;
void ktra(char k)
{
    list <int> :: iterator it=l.begin();
    if(k=='A')
    {
        l.push_back(*it);
        l.pop_front();
    }
    else
        if(k=='B')
        {
            it++;
            l.push_back(*it);
            l.erase(it);
        }
}
void enter()
{
    cin >> m;
    for(int i=0;i<m;i++)
        l.push_back(i);
    cin >> k;
    cin >> s;
    while(s!='.')
    {
        ktra(s);
        cin >> s;
    }
}
//void run()
//{
//    for(int i=0;i<s.size();i++)
//        ktra(s[i]);
//}
void out()
{
    list <int> :: iterator it=l.begin();
    advance(it,k-1);
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it++;
    cout << *it << endl;
}
int main()
{
    enter();
//    run();
    out();
}
