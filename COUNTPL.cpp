#include <iostream>
using namespace std;
const int maxN =256;
int n, F[maxN];
string S;
bool Free[maxN][maxN];
void Init()
{
    n=S.size();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((j==i)||(j==i-1))
                Free[i][j]=true;
            else
                Free[i][j]=false;
    for(int k=1;k<n;k++)
        for(int i=1;i<=n-k;i++)
        {
            int j=i+k;
            Free[i][j]=((S[i-1]==S[j-1])&&(Free[i+1][j-1]));
        }
}
void Optimize()
//    i,j :Byte;
{
    F[0]=0;
    for(int i=1;i<=n;i++)
    {
        F[i]=i;
        for(int j=1;j<=i;j++)
            if((Free[j][i])&&(F[i]>F[j-1]+1))
                F[i]=F[j-1]+1;
    }
}
int main()
{
    cin >> S;
    Init();
    Optimize();
    cout << F[n];
}
