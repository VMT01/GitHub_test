#include <bits/stdc++.h>
using namespace std;
string s;
int dem1[26], dem2[10005], kq1, kq2;

int main(){
    cin >> s;
    for(int i=0;i<s.size();i++) dem1[s[i]-'a']++;
    for(int i=1;i<=s.size();i++) dem2[i]++;
    for(int i=0;i<26;i++)
        for(int j=1;j<=dem1[i];j++) dem2[j]--;
    for(int i=s.size();i>1;i--){
        if(dem2[i]==0) continue;
        int ter=i;
        while((ter & 1)==0) kq1+=dem2[i], ter >>= 1;
        while((ter  %5)==0) kq2+=dem2[i], ter /= 5;
    }
    cout << min(kq1,kq2);
}
