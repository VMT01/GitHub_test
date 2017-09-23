#include <iostream>
using namespace std;
typedef pair<int,int> II;
    int n,a[101][101],amax=0,amin=120,lo,hi,d[101][101],
    pmin,pmax;
    II q[10001];
const int dh[]={0,0,0,-1,1};
const int dc[]={0,-1,1,0,0};
void khoitao()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
			d[i][j]=0;
}
bool ok(int i, int j)
{
    if(i>0&&i<=n&&j>0&&j<=n&&d[i][j]==0&&
       a[i][j]>=pmin&&a[i][j]<=pmax)return true;
    return false;
}
bool bfs()
{
    int l=1, r=0;
    if(a[1][1]>=pmin&&a[1][1]<=pmax)
    {
        d[1][1]=1;
        q[++r]=II(1,1);
    }
    while(l<=r)
    {
        II t=q[l++];
        int u=t.first,v=t.second;
        for(int p=1; p<=4; p++)
        {
            int u1=u+dh[p], v1=v+dc[p];
            if(ok(u1,v1))
            {
                if(u1==n&&v1==n) return true;
                d[u1][v1]=1;
                q[++r]=II(u1,v1);
            }
        }
    }
    return false;
}
bool f(int k)
{
    for(int i=amin; i<=amax-k; i++)
    {
        khoitao();
        pmin=i;
        pmax=i+k;
        if(bfs()) return true;
    }
    return false;
}
void chat()
{
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
}
int main()
{
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
        cin>>a[i][j];
        amax=max(amax,a[i][j]);
        amin=min(amin,a[i][j]);
    }
    lo=-1;
    hi=amax-amin;
    chat();
}
