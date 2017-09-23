#include <iostream>
using namespace std;
int m, n;
unsigned long long res, kq, h[405], l[405], cal[405], oc[5], tc[5][5];
string Map[405];
int fc(char k){
    for(int i=0;i<=4;i++)
        if(k-'A'==i) return i;
}
void reset(){
    for(int i=1;i<=n;i++){
        h[i]=0;
        cal[i]=0;
    }
    res=0;
}
void enter(){
    ios_base::sync_with_stdio("false");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> Map[i];
        Map[i]='#'+Map[i];
    }
}
void One_Character(){
    for(char k='A';k<='E';k++){
        reset();
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                h[j]=(Map[i][j]==k?h[j]+1:0);
                l[j]=j;
                while(h[l[j]-1]>=h[j]&&h[j]>0) l[j]=l[l[j]-1];
                if(Map[i][j]==k){
                    cal[j]=cal[l[j]-1]+h[j]*(j-l[j]+1);
                    res+=cal[j];
                }
                else cal[j]=0;
            }
        oc[fc(k)]=res;
    }
}
void Two_Charactters(){
    for(char k1='A';k1<='D';k1++)
        for(char k2=k1+1;k2<='E';k2++){
            reset();
            for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++){
                    h[j]=(Map[i][j]==k1||Map[i][j]==k2?h[j]+1:0);
                    l[j]=j;
                    while(h[l[j]-1]>=h[j]&&h[j]>0) l[j]=l[l[j]-1];
                    if(Map[i][j]==k1||Map[i][j]==k2){
                        cal[j]=cal[l[j]-1]+h[j]*(j-l[j]+1);
                        res+=cal[j];
                    }
                    else cal[j]=0;
                }
            tc[fc(k1)][fc(k2)]=res;
        }
}
void Three_Charecters(){
    for(char k1='A';k1<='C';k1++)
        for(char k2=k1+1;k2<='D';k2++)
            for(char k3=k2+1;k3<='E';k3++){
                reset();
                for(int i=1;i<=m;i++)
                    for(int j=1;j<=n;j++){
                        h[j]=(Map[i][j]==k1||Map[i][j]==k2||Map[i][j]==k3?h[j]+1:0);
                        l[j]=j;
                        while(h[l[j]-1]>=h[j]&&h[j]>0) l[j]=l[l[j]-1];
                        if(Map[i][j]==k1||Map[i][j]==k2||Map[i][j]==k3){
                            cal[j]=cal[l[j]-1]+h[j]*(j-l[j]+1);
                            res+=cal[j];
                        }
                        else cal[j]=0;
                    }
                kq+=res-tc[fc(k1)][fc(k2)]-tc[fc(k2)][fc(k3)]-tc[fc(k1)][fc(k3)]+oc[fc(k1)]+oc[fc(k2)]+oc[fc(k3)];
            }
}
int main(){
    enter();
    One_Character();
    Two_Charactters();
    Three_Charecters();
    cout << kq;
}
