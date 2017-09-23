#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void DownHeap(int p)
{
    int key=a[p];
    while(p*2<=n)
    {
        int c=p*2;
        if(c<n && a[c]<a[c+1]) c++;
        if(a[c]<=key) break;
        a[p]=a[c];
        p=c;
    }
    a[p]=key;
}

void UpHeap(int c)
{
    int key=a[c];
    while(c>=2)
    {
        int p=c/2;
        if(a[p]>=key) break;
        a[c]=a[p];
        c=p;
    }
    a[c]=key;
}

void AddHeap(int val)
{
    n++;
    a[n]=val;
    UpHeap(n);
}

void RemoveHeap()
{
    a[1]=a[n];
    n--;
    DownHeap(1);
}

void Init()
{
    a.resize(15000+100);
}

void Solve()
{
    char s;
    int tg;
    while (scanf("%c",&s) != EOF)
    {
        if(s=='+')
        {
            scanf("%d",&tg);
            if(n<15000)    AddHeap(tg);
        }
        if(s=='-')
        {
            if(n>0) tg=a[1];
            while(n>0 && tg==a[1])
                RemoveHeap();
        }
    }
    vector<int> b;
    while(n)
    {
        tg=a[1];
        if( b.empty() || tg!=b.back())
            b.push_back(tg);
        RemoveHeap();
    }
    cout<<b.size()<<endl;
    for (int i=0;i<b.size();i++)
        cout<<b[i]<<endl;
}

int main()
{
    Init();
    Solve();
}
