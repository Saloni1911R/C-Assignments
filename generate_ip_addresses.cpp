#include <iostream>
#include <string>
using namespace std;

bool valid(string s){
    if(s.size()==0 || s.size()>3) return false;
    if(s.size()>1 && s[0]=='0') return false;
    int val=0;
    for(char c: s) val = val*10 + (c-'0');
    return val>=0 && val<=255;
}

void gen(string &s){
    int n=s.size();
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                int l = n - i - j - k;
                if(l>=1 && l<=3){
                    string a = s.substr(0,i);
                    string b = s.substr(i,j);
                    string c = s.substr(i+j,k);
                    string d = s.substr(i+j+k,l);
                    if(valid(a) && valid(b) && valid(c) && valid(d))
                        cout<<a<<"."<<b<<"."<<c<<"."<<d<<"\n";
                }
            }
        }
    }
}

int main(){ string s; cin>>s; gen(s); return 0;}
