#include <bits/stdc++.h>
using namespace std;
string S;
void done(){
double res, sum, Suu;
int boo,dd,dS,cc;
    while (1){
        getline(cin,S);
        if (S=="?") break;
        int d1=0;
        int d2=0;
        for (int i=0; i<S.length(); ++i){
                if (S[i]=='.' || S[i]=='-' || (S[i]<='9' && S[i]>='0') ) d1=1;
            else
                if (S[i]!=' ')
                    d2=1;
        }
        if (d1 && d2) {
            cout<< "Error!"<< endl;
            continue;
        }
 if (d2==1){
            for (int i=0; i<S.length(); ++i)
                if (S[i]!=' ')
                    cout<<S[i];
            cout<<endl;
            continue;
        }
        S+=' ';
        sum=0;
        Suu=0;
        res=0;
        dS=0;
        dd=1;
        boo=0;
        for (int i=0; i<S.length(); ++i){
            if (S[i]==' ') {cc= (int) pow(10,dS); res+= (sum+ Suu/cc)*dd; dd=1; sum=0;boo=0;dS=0;Suu=0;}
            if (S[i]=='.') boo=1;
            if (S[i]=='-') dd=-1;
            if (S[i]!=' ' && S[i]!= '-' && S[i]!='.')
                if (boo==0)
                    sum = sum*10 + (int) (S[i])-48;
                else{
                    Suu = Suu*10 + (int) (S[i])-48;
                    ++dS;
                }
        }
        cout<<fixed<<setprecision(6)<<res<<endl;
    }
    //cout<<endl;
    }

int main(){
    done();
}
