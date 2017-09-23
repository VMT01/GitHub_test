#include <bits/stdc++.h>
using namespace std;
const int oo=1000000009;
int k, n, kq;
struct it{
    int Z1, S1, M1, Z2, S2, M2;
};

it t, d[20005];
queue <int> q1,q2,q3;
int F[5][5][5];

void BFS(){
    q1.push(t.Z1), q2.push(t.S1), q3.push(t.M1);
    while(!q1.empty() && !q2.empty() && !q3.empty()){
        int u1=q1.front();
        int u2=q2.front();
        int u3=q3.front();
        q1.pop();
        q2.pop();
        q3.pop();

        if(u1>=t.Z2 && u2>=t.S2 && u3>=t.M2) continue;
        for(int i=1;i<=n;i++){
            if(u1>=d[i].Z1 && u2>=d[i].S1 && u3>=d[i].M1 && (u1-d[i].Z1+d[i].Z2<=4) && (u2-d[i].S1+d[i].S2<=4) && (u3-d[i].M1+d[i].M2<=4)){
                int r1=u1-d[i].Z1+d[i].Z2;
                int r2=u2-d[i].S1+d[i].S2;
                int r3=u3-d[i].M1+d[i].M2;
                if(F[r1][r2][r3]>F[u1][u2][u3]+1 && F[u1][u2][u3]+1<=k){
                    F[r1][r2][r3]=F[u1][u2][u3]+1;
                    q1.push(r1);
                    q2.push(r2);
                    q3.push(r3);
                }
            }
        }
    }
}

int main(){
//    freopen("COLLECT.inp","r",stdin);
    ios_base::sync_with_stdio("false");cin.tie(NULL);cout.tie(NULL);

    cin >> k >> t.Z1 >> t.S1 >> t.M1 >> t.Z2 >> t.S2 >> t.M2;
    while(cin >> d[n+1].Z1 >> d[n+1].S1 >> d[n+1].M1 >> d[n+1].Z2 >> d[n+1].S2 >> d[n+1].M2) n++;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            for(int k=0;k<5;k++)
                F[i][j][k]=oo;

    F[t.Z1][t.S1][t.M1]=0;
    BFS();

    for(int i=t.Z2;i<5;i++)
        for(int j=t.S2;j<5;j++)
            for(int k=t.M2;k<5;k++)
                if(F[i][j][k]!=oo) kq++;

    if(kq==0){
        cout << -1;
        return 0;
    }
    cout << kq << endl;
    for(int i=t.Z2;i<5;i++)
        for(int j=t.S2;j<5;j++)
            for(int k=t.M2;k<5;k++)
                if(F[i][j][k]!=oo) cout << i << ' ' << j << ' ' << k << ' ' << F[i][j][k] << endl;
}
