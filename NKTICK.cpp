#include <iostream>
using namespace std;
int T[60001], R[60001], Fx[60001], n;
void enter()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> T[i];
    for(int i=1;i<=n-1;i++)
        cin >> R[i];
}
void optimize()
{
    Fx[1]=T[1];
    Fx[0]=0;
    for(int i=2;i<=n;i++)
        Fx[i]=min(Fx[i-1]+T[i],Fx[i-2]+R[i-1]);
}
int main()
{
    enter();
    optimize();
    cout << Fx[n];
}
